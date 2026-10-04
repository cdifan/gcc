/* -mos9math with soft float and NaNs honoured (the default): compares
   are still inline traps, as in Microware C; a comparison's value too,
   and its negation.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float" } */

int dlt (double a, double b) { return a < b ? 3 : 7; }
int dle (double a, double b) { return a <= b; }
int dnlt (double a, double b) { return !(a < b); }
int fne (float a, float b) { return a != b; }

/* { dg-final { scan-assembler-not "__ltdf2|__ledf2|__gedf2|__nesf2|__unord" } } */
/* { dg-final { scan-assembler-times {\.word 20} 3 } } */
/* { dg-final { scan-assembler-times {\.word 12} 1 } } */
