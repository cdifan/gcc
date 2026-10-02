/* Variadic functions defined with the OS-9 convention: with one named
   argument in d0, the prologue saves d1, where the first unnamed
   argument can be; with two named arguments, nothing needs saving.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

#include <stdarg.h>

int
one (int n, ...)
{
  va_list ap;
  int r;
  va_start (ap, n);
  r = va_arg (ap, int);
  va_end (ap);
  return r;
}

int
two (int a, int b, ...)
{
  va_list ap;
  int r;
  va_start (ap, b);
  r = va_arg (ap, int);
  va_end (ap);
  return r;
}

int __attribute__ ((stackcall)) w (int a, ...) { return a; }

/* { dg-final { scan-assembler "one:\n(\t\[^\n\]*\n)*\tmove.l %d1,\[0-9\]*\\(%sp\\)" } } */
/* { dg-final { scan-assembler-not "two:\n(\t\[^\n\]*\n)*\tmove.l %d1,\[0-9\]*\\(%sp\\)" } } */
