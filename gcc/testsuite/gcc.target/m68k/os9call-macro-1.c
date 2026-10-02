/* __OS9CALL__ and the calling-convention attributes under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

#ifndef __OS9CALL__
#error "__OS9CALL__ not defined"
#endif
#if !__has_attribute (os9call) || !__has_attribute (stackcall)
#error "calling-convention attributes not supported"
#endif
int dummy;
