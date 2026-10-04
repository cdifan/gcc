/* In strict ISO C, OSK is only defined in the reserved namespace.  */
/* { dg-do preprocess { target m68k-*-elfos9* } } */
/* { dg-options "-std=c99" } */

#ifdef OSK
#error "OSK defined in strict ISO C"
#endif
#if !defined __OSK || !defined __OSK__ || !defined _OSK || !defined _MPF68K
#error "__OSK, __OSK__, _OSK or _MPF68K not defined"
#endif
