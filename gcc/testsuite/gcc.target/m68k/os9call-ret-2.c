/* OS-9 convention with -m68881: float and double are still returned in
   d0 and d0:d1, not fp0, and fp0/fp1 are saved like other registers.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -m68881 -fomit-frame-pointer -w" } */

extern double g (void);

float rf (void) { return 1.5f; }
double rd (double x) { return x * 2; }
double cd (void) { return g () * 2; }

/* { dg-final { scan-assembler "rf:\n\tmove.l #0x3fc00000,%d0\n\trts" } } */
/* rd: x arrives in d0:d1 and the result leaves there.  */
/* { dg-final { scan-assembler "rd:\n\tfmovem #3,-\\(%sp\\)\n\tmove.l %d1,-\\(%sp\\)\n\tmove.l %d0,-\\(%sp\\)\n\tfmove.d \\(%sp\\)\\+,%fp0" } } */
/* { dg-final { scan-assembler "fmove.d %fp0,-\\(%sp\\)\n\tmove.l \\(%sp\\)\\+,%d0\n\tmove.l \\(%sp\\)\\+,%d1\n\tfmovem \\(%sp\\)\\+,#192\n\trts" } } */
/* cd: g's result is taken from d0:d1.  */
/* { dg-final { scan-assembler "jsr \\(%a0\\)\n\tmove.l %d1,-\\(%sp\\)\n\tmove.l %d0,-\\(%sp\\)\n\tfmove.d \\(%sp\\)\\+,%fp0" } } */
