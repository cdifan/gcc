/* Without -ma6rel, __A6REL__ isn't defined.  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-mpcrel" } */

#ifdef __A6REL__
#error __A6REL__ defined without -ma6rel
#endif
