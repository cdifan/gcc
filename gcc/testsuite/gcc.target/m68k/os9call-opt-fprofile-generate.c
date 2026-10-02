/* -fprofile-generate is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -fprofile-generate" } */
/* { dg-error "-fprofile-arcs" "" { target *-*-* } 0 } */
int dummy;
