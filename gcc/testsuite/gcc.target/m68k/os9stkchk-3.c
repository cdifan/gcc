/* -mos9stkchk requires -ma6rel.  */
/* { dg-do compile } */
/* { dg-options "-mos9stkchk -mpcrel" } */
/* { dg-error "requires '-ma6rel'" "" { target *-*-* } 0 } */
int dummy;
