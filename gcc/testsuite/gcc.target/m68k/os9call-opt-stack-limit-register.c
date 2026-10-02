/* -m68020 -msoft-float -fstack-limit-register=d1 is rejected under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel -m68020 -msoft-float -fstack-limit-register=d1" } */
/* { dg-error "-fstack-limit-register" "" { target *-*-* } 0 } */
int dummy;
