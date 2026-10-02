/* Without -mos9call, an os9call variadic definition is rejected too.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

int __attribute__ ((os9call)) v (int a, ...) { return a; }	/* { dg-error "variadic functions" } */
int w (int a, ...) { return a; }
