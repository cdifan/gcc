/* -mos9newline: the escape \n is a carriage return, as in Microware C.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline" } */

#ifndef __OS9NEWLINE__
#error "__OS9NEWLINE__ not defined"
#endif
#if '\n' != 13 || '\r' != 13 || '\l' != 10 || '\x0a' != 10 || '\012' != 10
#error "wrong values in #if"
#endif

_Static_assert ('\n' == 13, "newline");
_Static_assert ('\r' == 13, "carriage return");
_Static_assert ('\l' == 10, "line feed");
_Static_assert (sizeof ("\l") == 2, "line feed in a string");
_Static_assert ('\x0a' == 10, "hex line feed");
_Static_assert ('\012' == 10, "octal line feed");
_Static_assert (L'\n' == 13, "wide newline");

/* The bytes of string literals: 13 for \n and 10 for \l, which GCC writes
   as \r and \n in the assembler.  */
const char text[] = "ab\ncd";
const char text2[] = "x\ly";
/* { dg-final { scan-assembler {"ab\\rcd"} } } */
/* { dg-final { scan-assembler {"x\\ny"} } } */
