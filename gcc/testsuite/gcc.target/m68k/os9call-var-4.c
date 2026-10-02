/* Without -mos9call, an os9call variadic function can only be defined
   if its first unnamed argument can't be in d1.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

int __attribute__ ((os9call)) v (int a, ...) { return a; }	/* { dg-error "needs '-mos9call'" } */
int __attribute__ ((os9call)) v2 (int a, int b, ...) { return a + b; }
int w (int a, ...) { return a; }
