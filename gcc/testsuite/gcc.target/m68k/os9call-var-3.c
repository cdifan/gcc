/* Without -mos9call, an os9call variadic declaration can be called; the
   arguments are placed like a K&R call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

extern int __attribute__ ((os9call)) create (char *, int, int, ...);
int t (void) { return create ((char *) 0, 1111, 2222, 3333); }

/* { dg-final { scan-assembler "pea 3333.w\n\tpea 2222.w\n\tmove.l #1111,%d1\n\tmoveq #0,%d0" } } */
