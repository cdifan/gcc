/* -m68881 gives a warning under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -m68881" } */
/* { dg-warning "-m68881" "" { target *-*-* } 0 } */
int dummy;
