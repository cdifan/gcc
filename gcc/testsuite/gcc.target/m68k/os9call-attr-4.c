/* Conflicting declarations of the same function: os9call added to a
   function declared without it.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mpcrel -ma6rel" } */

int f (int);				/* { dg-message "previous declaration" } */
int __attribute__ ((os9call)) f (int);	/* { dg-error "conflicting types" } */
