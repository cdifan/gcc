/* Values kept across calls go to call-saved registers, which the
   prologue's movem saves, not to stack slots: a register more in a movem
   costs no code, a stack slot a stack adjustment each way.  With the
   default costs GCC 16 kept the first call's result in a stack slot and
   reloaded x from its argument slot.
   fixed: 2026-11-01 m68k: callee-save and frame-allocation costs
*/
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

extern int g (int);

int
f (int x, int *q)
{
  int a = g (x);
  int b = g (x + 1);
  return a + b + x + *q;
}

/* d2, a2 and a3: x, the first call's result and g's address.  */
/* { dg-final { scan-assembler "movem.l #8240,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler-not "subq.l #\[48\],%sp" } } */
