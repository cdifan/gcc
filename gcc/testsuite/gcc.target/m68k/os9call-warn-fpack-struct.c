/* -fpack-struct gives a warning under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel -fpack-struct" } */
/* { dg-warning "-fpack-struct" "" { target *-*-* } 0 } */
int dummy;
