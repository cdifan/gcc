/* -mos9newline=microware is -mos9newline; -mos9newline=standard after it
   is -mno-os9newline.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline=microware" } */

#if __OS9NEWLINE__ != 1
#error "__OS9NEWLINE__ not 1"
#endif
#if '\n' != 13 || '\r' != 13 || '\l' != 10
#error "wrong values in #if"
#endif

_Static_assert ('\n' == 13, "newline");
_Static_assert ('\r' == 13, "carriage return");
_Static_assert ('\l' == 10, "line feed");

const char text[] = "a\nb\rc\ld";
/* { dg-final { scan-assembler {"a\\rb\\rc\\nd"} } } */
