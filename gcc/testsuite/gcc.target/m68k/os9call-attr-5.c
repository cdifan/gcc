/* Conflicting calling-convention attributes are an error under
   -mos9call too, in either order.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

int __attribute__ ((os9call)) __attribute__ ((stackcall)) f (int); /* { dg-error "not compatible" } */
int __attribute__ ((stackcall, os9call)) g (int); /* { dg-error "not compatible" } */
int (__attribute__ ((os9call, stackcall)) *p) (int); /* { dg-error "not compatible" } */
