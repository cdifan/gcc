/* The macros Microware C predefines for OS-9/68K, for the CPU32.  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-mcpu=cpu32 -msoft-float" } */

#if !defined _OSK || !defined _MPF68K || !defined _MPFCPU32
#error "_OSK, _MPF68K or _MPFCPU32 not defined"
#endif
#if defined _MPF68020 || defined _FPF881
#error "_MPF68020 or _FPF881 defined"
#endif
