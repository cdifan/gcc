/* -pg is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -pg" } */
/* { dg-error "-pg" "" { target *-*-* } 0 } */
int dummy;
