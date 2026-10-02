/* __builtin_apply is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

extern int target ();

int
forward (int a)
{
  void *args = __builtin_apply_args ();
  __builtin_apply ((void (*) ()) target, args, 16);	/* { dg-error "__builtin_apply" } */
  return 0;
}
