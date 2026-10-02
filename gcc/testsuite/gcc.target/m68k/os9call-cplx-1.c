/* Complex multiply and divide call libgcc with the stack convention
   under -mos9call: all arguments pushed, the result in d0:d1.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

_Complex float m (_Complex float a, _Complex float b) { return a * b; }
_Complex float d (_Complex float a, _Complex float b) { return a / b; }

/* { dg-final { scan-assembler "lea \\(__mulsc3:w,%pc\\),%a\[01\]\n\tjsr" } } */
/* { dg-final { scan-assembler "lea \\(__divsc3:w,%pc\\),%a\[01\]\n\tjsr" } } */
/* Nothing is passed in d0/d1 to them, and no result buffer in a0.  */
/* { dg-final { scan-assembler-not "move.l \[^\n\]*,%d\[01\]\n\t(move.l \[^\n\]*\n\t)?lea \\(__(mul|div)sc3" } } */
