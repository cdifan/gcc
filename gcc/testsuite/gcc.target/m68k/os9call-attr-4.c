/* Conflicting declarations of the same function.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mpcrel -ma6rel" } */

int __attribute__ ((os9call)) f (int);	/* { dg-message "previous declaration" } */
int f (int);				/* { dg-error "conflicting types" } */
