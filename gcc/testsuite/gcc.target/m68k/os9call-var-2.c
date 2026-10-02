/* Variadic functions can't be defined with the OS-9 convention yet.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

int v (int a, ...) { return a; }	/* { dg-error "variadic functions" } */
int __attribute__ ((stackcall)) w (int a, ...) { return a; }
