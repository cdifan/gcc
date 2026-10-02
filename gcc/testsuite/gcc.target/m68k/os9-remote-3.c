/* The remote attribute needs static storage.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

int f (void) { int y __attribute__ ((remote)) = 1; return y; }	/* { dg-warning "only applies to variables with static storage" } */
