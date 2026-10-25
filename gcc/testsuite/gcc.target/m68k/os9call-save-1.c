/* OS-9 convention, callee register saves: d1 unless it carries an
   argument or the return value, a0 and a1 when used or when the function
   makes calls; never d0.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

extern void __attribute__ ((stackcall)) clobber (void);

int leaf1 (int a) { return a + 1; }
int copy4 (int *p) { int *q = p + 4; q[0] = p[0]; q[1] = p[1]; return q[0] + q[1]; }
int nonleaf1 (int a) { clobber (); return a; }
int nonleaf2 (int a, int b) { clobber (); return a + b; }
long long ret64 (int a) { clobber (); return (long long) a << 32 | 5; }

/* leaf1 touches nothing but d0.  */
/* { dg-final { scan-assembler "leaf1:\n\taddq.l #1,%d0\n\trts" } } */
/* copy4: a leaf using d1, a0 and a1 saves them.  */
/* { dg-final { scan-assembler "copy4:\n\tmovem.l #16576,-\\(%sp\\)" } } */
/* nonleaf1: d1, a0, a1 (mask 0x302; a is kept in a stack slot).  */
/* { dg-final { scan-assembler "nonleaf1:\n\tsubq.l #4,%sp\n\tmovem.l #16576,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler "movem.l \\(%sp\\)\\+,#770\n" } } */
/* nonleaf2: d1 carries argument 2, so only a0 and a1.  */
/* { dg-final { scan-assembler "nonleaf2:\n\tsubq.l #8,%sp\n\tmove.l %a1,-\\(%sp\\)\n\tmove.l %a0,-\\(%sp\\)\n\tlea" } } */
/* ret64: d1 carries half of the result, so only a0 and a1.  */
/* { dg-final { scan-assembler "ret64:\n\tsubq.l #4,%sp\n\tmove.l %a1,-\\(%sp\\)\n\tmove.l %a0,-\\(%sp\\)\n\tlea" } } */
/* d0 is never saved.  */
/* { dg-final { scan-assembler-not "move.l %d0,-\\(%sp\\)" } } */
