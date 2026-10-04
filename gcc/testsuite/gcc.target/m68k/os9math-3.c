/* -mos9math with soft float: compares are inline traps (T$DCmp, T$FCmp)
   and branches, here with -ffinite-math-only.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float -ffinite-math-only" } */

int dlt (double a, double b) { return a < b ? 3 : 7; }
int dge (double a, double b) { if (a >= b) return 4; return 9; }
int feq (float a, float b) { return a == b ? 5 : 2; }
int fgt (float a, float b) { return a > b ? 6 : 1; }

/* { dg-final { scan-assembler-not "__ltdf2|__gedf2|__eqsf2|__gtsf2" } } */
/* { dg-final { scan-assembler-times {\.word 20} 2 } } */
/* { dg-final { scan-assembler-times {\.word 12} 2 } } */
