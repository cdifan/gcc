/* -malign-int gives a warning under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -malign-int" } */
/* { dg-warning "-malign-int" "" { target *-*-* } 0 } */
int dummy;
