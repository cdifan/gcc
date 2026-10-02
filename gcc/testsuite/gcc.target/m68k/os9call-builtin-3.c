/* An unknown -mbuiltin= value is rejected.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mbuiltin=newlib -mpcrel -ma6rel" } */
/* { dg-error "unrecognized argument" "" { target *-*-* } 0 } */
/* { dg-message "valid arguments" "" { target *-*-* } 0 } */
int dummy;
