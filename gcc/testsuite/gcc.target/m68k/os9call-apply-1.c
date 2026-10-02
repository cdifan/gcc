/* __builtin_apply_args, __builtin_apply and __builtin_return are
   rejected under -mos9call (once per file).  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

extern int target ();

int
forward (int a)
{
  void *args = __builtin_apply_args ();	/* { dg-error "not supported with" } */
  __builtin_apply ((void (*) ()) target, args, 16);
  return 0;
}
