/* Without -mos9call, only os9call functions save d1, a0 and a1.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel -fomit-frame-pointer" } */

extern void clobber (void);

int __attribute__ ((os9call)) mw (int a) { clobber (); return a; }
int plain (int a) { clobber (); return a; }

/* mw: d1, a0, a1, and d2 for a across the call (mask 0x306).  */
/* { dg-final { scan-assembler "mw:\n\tmovem.l #24768,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler "plain:\n\tlea \\(clobber:w,%pc\\),%a0\n\tjsr \\(%a0\\)\n\tmove.l 4\\(%sp\\),%d0\n\trts" } } */
