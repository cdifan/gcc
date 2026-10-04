/* -mos9math is accepted, and the code is the same: the soft-float routines
   are replaced at link time (libos9math).  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9math -msoft-float" } */

double add (double a, double b) { return a + b; }

/* { dg-final { scan-assembler "__adddf3" } } */
