/* Without -mos9regfunc, register on a function declaration stays an
   error, as in ISO C.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "" } */

char *
first (char *s)
{
  register char *p, *look (); /* { dg-error "invalid storage class for function .look." } */
  p = look (s, 'x');
  return p;
}
