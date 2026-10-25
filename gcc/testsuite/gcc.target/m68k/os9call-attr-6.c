/* A declaration without the attribute after an os9call one takes its type:
   the call uses the OS-9 convention (the argument in d0).  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

int __attribute__ ((os9call)) f (int);
int f (int);
int g (void) { return f (1); }

/* { dg-final { scan-assembler "moveq #1,%d0" } } */
/* { dg-final { scan-assembler-not "pea 1.w" } } */
