/* OS-9 convention, callee side: arguments are read from d0, d1 and the
   stack, following the same rules as the caller.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

struct s1 { char c; };

int g1 (int a) { return a + 1111; }
int g2 (int a, int b) { return b; }
int g3 (int a, int b, int c) { return c; }
int gd (double x, int y) { return y; }
int gs (struct s1 s, int y) { return s.c; }
int gsi (struct s1 s, int y) { return y; }

/* g1: a in d0.  */
/* { dg-final { scan-assembler "g1:\n\tadd.l #1111,%d0\n\trts" } } */
/* g2: b in d1.  */
/* { dg-final { scan-assembler "g2:\n\tmove.l %d1,%d0\n\trts" } } */
/* g3, gd: c and y in the first stack slot.  */
/* { dg-final { scan-assembler "g3:\n\tmove.l 4\\(%sp\\),%d0\n\trts" } } */
/* { dg-final { scan-assembler "gd:\n\tmove.l 4\\(%sp\\),%d0\n\trts" } } */
/* gs: the 1-byte struct at the start of its slot; gsi: y after it.  */
/* { dg-final { scan-assembler "gs:\n\tmove.b 4\\(%sp\\),%d0" } } */
/* { dg-final { scan-assembler "gsi:\n\tmove.l 8\\(%sp\\),%d0\n\trts" } } */
