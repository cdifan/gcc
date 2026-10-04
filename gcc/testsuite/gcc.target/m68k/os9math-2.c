/* -mos9math with soft float: arithmetic and conversions are inline traps
   to OS-9's math module, not libgcc calls.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float" } */

double dadd (double a, double b) { return a + b; }
double dsub (double a, double b) { return a - b; }
double dmul (double a, double b) { return a * b; }
double ddiv (double a, double b) { return a / b; }
float fadd (float a, float b) { return a + b; }
float fsub (float a, float b) { return a - b; }
float fmul (float a, float b) { return a * b; }
float fdiv (float a, float b) { return a / b; }
double ltod (long l) { return l; }
double utod (unsigned long u) { return u; }
long dtol (double d) { return d; }
unsigned long dtou (double d) { return d; }
float ltof (long l) { return l; }
float utof (unsigned long u) { return u; }
long ftol (float f) { return f; }
unsigned long ftou (float f) { return f; }
double ftod (float f) { return f; }
float dtof (double d) { return d; }

/* { dg-final { scan-assembler-times "trap #15" 18 } } */
/* { dg-final { scan-assembler-not "__adddf3|__subdf3|__muldf3|__divdf3" } } */
/* { dg-final { scan-assembler-not "__addsf3|__subsf3|__mulsf3|__divsf3" } } */
/* { dg-final { scan-assembler-not "__float|__fix|__extendsfdf2|__truncdfsf2" } } */
/* { dg-final { scan-assembler {\.word 14} } } */
/* { dg-final { scan-assembler {\.word 40} } } */
