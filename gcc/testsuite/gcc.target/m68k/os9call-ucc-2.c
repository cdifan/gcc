/* -mos9call=ucc: a variadic function with one named argument (in d0)
   finds its unnamed ones on the stack, as Ultra C's do: d1 isn't saved
   for va_arg, and va_start points at the first stack argument.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call=ucc -mpcrel -ma6rel" } */

#include <stdarg.h>

int
sum (int n, ...)
{
  va_list ap;
  int s = n;
  va_start (ap, n);
  s += va_arg (ap, int);
  s += va_arg (ap, int);
  va_end (ap);
  return s;
}

/* { dg-final { scan-assembler-not "%d1" } } */
/* { dg-final { scan-assembler "\\(%sp\\)" } } */
