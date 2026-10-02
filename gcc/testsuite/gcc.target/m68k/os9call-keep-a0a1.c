/* -mos9call: OS-9 convention callees preserve a0 and a1, so callers keep
   values there across the calls, direct and indirect, instead of saving
   call-saved registers.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel -mos9call" } */

extern int g (int);

int
f (int *p, int *q)
{
  int a = g (*p);
  a += g (*q);
  return a + *p + *q;
}

int
h (int *p, int (*fp) (int))
{
  int a = fp (*p);
  a += fp (p[1]);
  return a + *p;
}

/* Values live across the calls are in a0/a1; no d2, a4 to save.  */
/* { dg-final { scan-assembler "\\(%a\[01\]\\)" } } */
/* { dg-final { scan-assembler-not "%d2" } } */
/* { dg-final { scan-assembler-not "%a4" } } */
