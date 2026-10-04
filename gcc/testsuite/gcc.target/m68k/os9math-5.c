/* -mos9math with the 68881: the FPU, no traps.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -m68020 -m68881" } */

double dadd (double a, double b) { return a + b; }
int dlt (double a, double b) { return a < b; }

/* { dg-final { scan-assembler "fadd" } } */
/* { dg-final { scan-assembler-not "trap #15" } } */
