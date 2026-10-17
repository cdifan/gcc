/* -mos9call=ucc: va_list is a plain pointer to the next stack argument,
   as Ultra C's (which its vprintf takes); va_arg steps through 4-byte
   stack slots.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call=ucc -mpcrel -ma6rel" } */

#include <stdarg.h>

int pointer_sized[sizeof (va_list) == sizeof (void *) ? 1 : -1];

extern int vsum (int, va_list);

int
first (int n, ...)
{
  va_list ap;
  int r;
  va_start (ap, n);
  r = vsum (n, ap);
  va_end (ap);
  return r;
}

/* va_start: the address of the first stack argument (past the three
   saved registers and the return address), passed in d1.  */
/* { dg-final { scan-assembler "moveq #16,%d1\n\tadd.l %sp,%d1" } } */
