/* Frames of 32 KB or more with -m68881: the FPU registers are restored
   before a1, which is the index register.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -m68881 -fno-omit-frame-pointer -w" } */

extern void use (char *);

int big (int a) { char buf[40000]; use (buf); return a; }
double bigd (double x) { char buf[40000]; use (buf); return x; }

/* { dg-final { scan-assembler "fmovem -24\\(%a1,%a5.l\\),#192\n\tmovem.l -40\\(%a1,%a5.l\\),#774\n\tunlk" } } */
/* { dg-final { scan-assembler "fmovem -24\\(%a1,%a5.l\\),#192\n\tmovem.l -40\\(%a1,%a5.l\\),#780\n\tunlk" } } */
