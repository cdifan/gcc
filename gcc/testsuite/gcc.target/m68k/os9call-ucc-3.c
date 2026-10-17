/* -mos9call=ucc turns the OS-9 convention on and defines __OS9CALL_UCC__
   besides __OS9CALL__.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call=ucc -mpcrel -ma6rel" } */

#ifndef __OS9CALL__
#error "__OS9CALL__ not defined"
#endif
#ifndef __OS9CALL_UCC__
#error "__OS9CALL_UCC__ not defined"
#endif
int dummy;
