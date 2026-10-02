/* __builtin_return alone is rejected under -mos9call too.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

void
ret (void *result)
{
  __builtin_return (result);	/* { dg-error "not supported with" } */
}
