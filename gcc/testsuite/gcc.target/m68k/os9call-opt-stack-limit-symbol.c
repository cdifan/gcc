/* -m68020 -msoft-float -fstack-limit-symbol=__stklimit is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -m68020 -msoft-float -fstack-limit-symbol=__stklimit" } */
/* { dg-error "-fstack-limit-symbol" "" { target *-*-* } 0 } */
int dummy;
