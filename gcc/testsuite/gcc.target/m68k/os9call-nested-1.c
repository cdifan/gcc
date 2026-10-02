/* Under -mos9call, nested functions can be called directly, but not
   through a trampoline.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

extern void use (int (*) (int));

int
direct (int x)
{
  int inner (int y) { return x + y; }
  return inner (1);
}

int
indirect (int x)
{
  int inner (int y) { return x + y; }	/* { dg-error "trampoline" } */
  use (inner);
  return 0;
}
