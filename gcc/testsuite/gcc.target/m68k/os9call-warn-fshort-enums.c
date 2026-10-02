/* -fshort-enums gives a warning under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel -fshort-enums" } */
/* { dg-warning "-fshort-enums" "" { target *-*-* } 0 } */
int dummy;
