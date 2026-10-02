/* Frames of 32 KB or more with -m68881: the FPU registers are restored
   before a1, which is the index register.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -m68881 -fno-omit-frame-pointer -w" } */

extern void use (char *);

int big (int a) { char buf[40000]; use (buf); return a; }
double bigd (double x) { char buf[40000]; use (buf); return x; }

/* The FPU registers first, then the integer registers including a1 (which
   registers depends on the allocation: callers keep values in a0/a1
   across OS-9 convention calls).  */
/* { dg-final { scan-assembler-times "fmovem -24\\(%a1,%a5.l\\),#192\n\tmovem.l -\[0-9\]+\\(%a1,%a5.l\\),#\[0-9\]+\n\tunlk" 2 } } */
