/* -mos9stkchk: Microware C 3.2's stack check at the start of every
   function: move.l #-N,d0 and bsr _stkcheck, with N = frame + register
   saves + link + 64 (leaf) or 68.  d0 is saved around it when it holds
   an argument.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mos9stkchk -mpcrel -ma6rel -fomit-frame-pointer" } */

extern void g (void);
extern void use (char *);

int leaf (int a) { return a + 1; }
void noargs (void) { g (); }
int frame (int a) { char buf[100]; use (buf); return a; }

/* leaf: no frame, d0 holds a: 64.  */
/* { dg-final { scan-assembler "leaf:\n\tmove.l %d0,-\\(%sp\\)\n\tmoveq #-64,%d0\n\tbsr.w _stkcheck\n\tmove.l \\(%sp\\)\\+,%d0\n" } } */
/* noargs: saves d1/a0/a1 (12) + 68 = 80, d0 not saved.  */
/* { dg-final { scan-assembler "noargs:\n\tmoveq #-80,%d0\n\tbsr.w _stkcheck\n" } } */
/* frame: 100 bytes of locals + saves + 68.  */
/* { dg-final { scan-assembler "frame:\n\tmove.l %d0,-\\(%sp\\)\n\tmove.l #-\[0-9\]+,%d0\n\tbsr.w _stkcheck\n\tmove.l \\(%sp\\)\\+,%d0\n" } } */
