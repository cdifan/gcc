/* -finstrument-functions is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -finstrument-functions" } */
/* { dg-error "-finstrument-functions" "" { target *-*-* } 0 } */
int dummy;
