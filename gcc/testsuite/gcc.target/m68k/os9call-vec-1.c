/* Under the OS-9 convention, vectors are passed on the stack and
   returned in memory, like aggregates.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

typedef int v2si __attribute__ ((vector_size (8)));

v2si rv (v2si x) { return x; }

/* { dg-final { scan-assembler "rv:\n\tmove.l %a0,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler "move.l %d0,\\(%a0\\)\n\tmove.l %d1,4\\(%a0\\)" } } */
