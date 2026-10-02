/* -mshort is rejected under -mos9call.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel -mshort" } */
/* { dg-error "-mshort" "" { target *-*-* } 0 } */
int dummy;
