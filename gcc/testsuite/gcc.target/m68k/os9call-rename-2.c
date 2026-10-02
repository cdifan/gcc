/* As os9call-rename-1.c, with the FPU: the ABI counts fp0 and fp1 as
   clobbered, but an OS-9 convention function preserves them.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -frename-registers -m68020 -m68881 -mpcrel -ma6rel -mos9call -w" } */

_Complex double
foo (int x)
{
  _Complex double r;
  __real r = x + 1;
  __imag r = x - 1;
  return r;
}

/* { dg-final { scan-assembler-not "%fp1" } } */
