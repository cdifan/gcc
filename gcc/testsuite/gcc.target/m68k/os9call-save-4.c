/* A function that saves only call-clobbered registers (d1, a0, a1) must
   still restore them; the restores mustn't be deleted as dead.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

extern void __attribute__ ((stackcall)) clobber (void);

int only_scratch (int a) { clobber (); return 1; }

/* { dg-final { scan-assembler "only_scratch:\n\tmovem.l #16576,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler "movem.l \\(%sp\\)\\+,#770\n\trts" } } */
