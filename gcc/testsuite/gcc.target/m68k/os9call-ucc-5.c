/* -mno-os9call wins over -mos9call=ucc: the stack convention, and
   neither macro.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call=ucc -mno-os9call -mpcrel -ma6rel" } */

#ifdef __OS9CALL__
#error "__OS9CALL__ defined"
#endif
#ifdef __OS9CALL_UCC__
#error "__OS9CALL_UCC__ defined"
#endif

extern void p2 (int, int);
void t1 (void) { p2 (1111, 1112); }

/* { dg-final { scan-assembler "pea 1112.w\n\tpea 1111.w" } } */
