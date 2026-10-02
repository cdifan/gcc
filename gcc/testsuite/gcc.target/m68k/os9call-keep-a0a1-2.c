/* -mos9call: stack convention callees (stackcall, libcalls such as
   __muldi3) may clobber a0 and a1, so callers don't keep values there
   across those calls.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel -mos9call" } */

extern int s (int) __attribute__ ((stackcall));

int
f (int *p, int *q)
{
  int a = s (*p);
  a += s (*q);
  return a + *p + *q;
}

long long
m (long long *p, long long x)
{
  long long y = x * *p;
  return y * p[1];
}

/* The pointers are in call-saved registers, not a0/a1.  */
/* { dg-final { scan-assembler-not "\\(%a\[01\]\\)" } } */
/* { dg-final { scan-assembler-not "\\(%a\[01\]," } } */
