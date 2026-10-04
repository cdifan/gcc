/* The macros Microware C predefines for OS-9/68K, for the 68020 with a
   68881.  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-m68020 -m68881" } */

#if !defined OSK || !defined _OSK || !defined _MPF68K || !defined _BIG_END
#error "OSK, _OSK, _MPF68K or _BIG_END not defined"
#endif
#if !defined _MPF68020 || !defined _FPF881
#error "_MPF68020 or _FPF881 not defined"
#endif
#ifdef _MPFCPU32
#error "_MPFCPU32 defined"
#endif
