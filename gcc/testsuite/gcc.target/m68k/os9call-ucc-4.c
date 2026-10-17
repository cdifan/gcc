/* -mos9call=c32 is -mos9call: the first unnamed argument can be in d1,
   and __OS9CALL_UCC__ isn't defined.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call=c32 -mpcrel -ma6rel" } */

#ifndef __OS9CALL__
#error "__OS9CALL__ not defined"
#endif
#ifdef __OS9CALL_UCC__
#error "__OS9CALL_UCC__ defined"
#endif

extern void v1 (int, ...);
void t1 (void) { v1 (1111, 1112, 1113); }

/* { dg-final { scan-assembler "pea 1113.w\n\tmove.l #1112,%d1\n\tmove.l #1111,%d0" } } */
