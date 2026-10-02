/* Misplaced and conflicting calling-convention attributes.  */
/* { dg-do compile } */
/* { dg-options "-mpcrel -ma6rel" } */

int v __attribute__ ((os9call));	/* { dg-warning "only applies to function types" } */
int __attribute__ ((os9call)) __attribute__ ((stackcall)) f (int); /* { dg-error "not compatible" } */
int __attribute__ ((stackcall, os9call)) g (int); /* { dg-error "not compatible" } */
