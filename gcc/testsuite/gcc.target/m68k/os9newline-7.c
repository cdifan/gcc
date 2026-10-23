/* -mos9newline=standard, also after -mos9newline: ISO C's escapes, as
   -mno-os9newline.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline -mos9newline=standard" } */

#ifdef __OS9NEWLINE__
#error "__OS9NEWLINE__ defined"
#endif
#if '\n' != 10 || '\r' != 13
#error "wrong values in #if"
#endif

_Static_assert ('\n' == 10, "newline");
_Static_assert ('\r' == 13, "carriage return");

int el = '\l';	/* { dg-warning "unknown escape sequence" } */
