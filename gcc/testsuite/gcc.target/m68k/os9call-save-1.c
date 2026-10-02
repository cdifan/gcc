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
/* copy4: a leaf using a0 and d1 saves both.  */
/* { dg-final { scan-assembler "copy4:\n\tmove.l %a0,-\\(%sp\\)\n\tmove.l %d1,-\\(%sp\\)" } } */
/* nonleaf1: d1, d2, a0, a1 (mask 0x306).  */
/* { dg-final { scan-assembler "nonleaf1:\n\tmovem.l #24768,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler "movem.l \\(%sp\\)\\+,#774\n" } } */
/* nonleaf2: d1 carries argument 2, so d2, d3, a0, a1 (mask 0x30c).  */
/* { dg-final { scan-assembler "movem.l \\(%sp\\)\\+,#780\n" } } */
/* ret64: d1 carries half of the result, so d2, a0, a1 (mask 0x304).  */
/* { dg-final { scan-assembler "movem.l \\(%sp\\)\\+,#772\n" } } */
/* d0 is never saved.  */
/* { dg-final { scan-assembler-not "move.l %d0,-\\(%sp\\)" } } */
