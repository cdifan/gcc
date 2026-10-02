/* Under -mos9call, _Unwind_Resume keeps the stack convention (C with
   -fexceptions and a cleanup variable).  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fexceptions" } */

extern void done (int *);
extern void work (void);

void
f (void)
{
  int x __attribute__ ((cleanup (done))) = 1111;
  work ();
}

/* The exception pointer is pushed: in a data register, or in a0/a1, where
   it can stay across the OS-9 convention call to done.  */
/* { dg-final { scan-assembler "move.l %\[ad\]\[0-7\],-\\(%sp\\)\n(\t\\.cfi\[^\n\]*\n)?\tlea \\(_Unwind_Resume" } } */
