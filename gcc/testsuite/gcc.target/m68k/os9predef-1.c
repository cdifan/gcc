/* The macros Microware C predefines for OS-9/68K, for the 68000.  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-m68000 -msoft-float" } */

#if !defined OSK || !defined __OSK || !defined __OSK__ || !defined _OSK
#error "OSK not defined"
#endif
#if !defined _MPF68K || !defined _BIG_END || !defined mc68000
#error "_MPF68K, _BIG_END or mc68000 not defined"
#endif
#if defined _MPF68020 || defined _MPFCPU32 || defined _FPF881
#error "68020, CPU32 or 68881 macro defined"
#endif
#if defined _OS9 || defined _LIL_END
#error "_OS9 or _LIL_END defined"
#endif
