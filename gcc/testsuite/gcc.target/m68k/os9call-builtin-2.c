/* -mbuiltin=stackcall is the default: same as os9call-libcall-1.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mbuiltin=stackcall -mpcrel -ma6rel" } */

typedef __SIZE_TYPE__ size_t;
extern void *malloc (size_t);
void *alloc (void) { return malloc (1111); }

/* { dg-final { scan-assembler "pea 1111.w\n\tlea \\(malloc" } } */
