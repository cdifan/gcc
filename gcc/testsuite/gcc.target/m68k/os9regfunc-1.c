/* -mos9regfunc: register on a function declaration in a block is ignored,
   with a warning, as in Microware C 3.2; the function is an ordinary
   external one.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9regfunc" } */

char *
first (char *s)
{
  register char *p, *look (); /* { dg-warning ".register. ignored on function .look." } */
  p = look (s, 'x');
  return p;
}

/* { dg-final { scan-assembler "look" } } */
