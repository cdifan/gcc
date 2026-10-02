/* No sibling calls from OS-9 convention functions (the epilogue restores
   d1, a0 and a1), nor from stack convention functions to OS-9 ones.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

extern int __attribute__ ((os9call)) mwf (int);
extern int plainf (int);

int __attribute__ ((os9call)) from_os9 (int a) { return plainf (a + 1); }
int to_os9 (int a) { return mwf (a + 1); }
int plain_to_plain (int a) { return plainf (a + 1); }

/* { dg-final { scan-assembler-times "jmp \\(%a\[01\]\\)" 1 } } */
