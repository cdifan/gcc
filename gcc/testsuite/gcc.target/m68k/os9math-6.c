/* -mos9math with soft float: isnan and isunordered check for NaNs with
   libgcc's __unord<mode>2, which the math module can't.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float" } */

int disnan (double d) { return __builtin_isnan (d); }
int fisnan (float f) { return __builtin_isnan (f); }
int dunord (double a, double b) { return __builtin_isunordered (a, b); }

/* { dg-final { scan-assembler-times {jb?sr[ \t]+__unorddf2} 2 } } */
/* { dg-final { scan-assembler-times {jb?sr[ \t]+__unordsf2} 1 } } */
/* { dg-final { scan-assembler-not "trap #15" } } */
