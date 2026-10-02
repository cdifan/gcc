/* No -ma6rel gives a warning under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel  " } */
/* { dg-warning "-ma6rel" "" { target *-*-* } 0 } */
int dummy;
