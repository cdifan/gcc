/* -mrtd is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -mrtd" } */
/* { dg-error "-mrtd" "" { target *-*-* } 0 } */
int dummy;
