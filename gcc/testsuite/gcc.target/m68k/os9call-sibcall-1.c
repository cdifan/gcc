/* No sibling calls from OS-9 convention functions (the epilogue restores
   d1, a0 and a1), nor from stack convention functions to OS-9 ones.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

extern int __attribute__ ((os9call)) mwf (int);
extern int plainf (int);

int __attribute__ ((os9call)) from_os9 (int a) { return plainf (a + 1); }
int to_os9 (int a) { return mwf (a + 1); }
int plain_to_plain (int a) { return plainf (a + 1); }

/* { dg-final { scan-assembler-not "from_os9:\n(\t\[^\n\]*\n)*\tjmp" } } */
/* { dg-final { scan-assembler-not "to_os9:\n(\t\[^\n\]*\n)*\tjmp" } } */
/* { dg-final { scan-assembler "plain_to_plain:\n(\t\[^\n\]*\n)*\tjmp \\(%a\[01\]\\)" } } */
