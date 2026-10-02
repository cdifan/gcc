/* The remote attribute needs -ma6rel, and static storage.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel" } */

int x __attribute__ ((remote));	/* { dg-warning "ignored without '-ma6rel'" } */
