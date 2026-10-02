/* -ma6rel defines __A6REL__, for assembly code that addresses data
   relative to a6 (libgcc's lb1sf68.S).  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-mpcrel -ma6rel" } */

#ifndef __A6REL__
#error __A6REL__ not defined with -ma6rel
#endif
