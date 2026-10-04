/* -mos9math with soft float: an addition is an inline trap to OS-9's math
   module (T$DAdd), not a call of libgcc's __adddf3.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float" } */

double add (double a, double b) { return a + b; }

/* { dg-final { scan-assembler "trap #15" } } */
/* { dg-final { scan-assembler-not "__adddf3" } } */
