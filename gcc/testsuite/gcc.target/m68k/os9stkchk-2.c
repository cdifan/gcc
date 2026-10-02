/* -mos9stkchk without -mos9call (stack convention: d0 holds no
   argument), with a frame pointer, and not in interrupt handlers.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9stkchk -mpcrel -ma6rel -fno-omit-frame-pointer" } */

extern void use (char *);

int frame (int a) { char buf[100]; use (buf); return a; }
void __attribute__ ((interrupt_handler)) irq (void) { use (0); }

/* frame: link (4) + 100 bytes of locals + 68 = 172, before the link.  */
/* { dg-final { scan-assembler "frame:\n\tmove.l #-172,%d0\n\tbsr.w _stkcheck\n\tlink.w %a5" } } */
/* { dg-final { scan-assembler-not "irq:\n(\t\[^\n\]*\n)*\tbsr.w _stkcheck" } } */
