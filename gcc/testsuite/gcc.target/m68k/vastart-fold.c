/* Without -mos9call, va_start is folded as usual: the OS-9 convention's
   va_start hook is only installed with -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

#include <stdarg.h>

int
g (int a, ...)
{
  va_list ap;
  int r;
  va_start (ap, a);
  r = va_arg (ap, int);
  va_end (ap);
  return r;
}

/* { dg-final { scan-assembler "move.l 8\\(%sp\\),%d0" } } */
/* { dg-final { scan-assembler-not "lea" } } */
