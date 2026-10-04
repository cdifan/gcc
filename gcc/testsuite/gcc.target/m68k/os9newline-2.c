/* Without -mos9newline, \n stays a line feed, also under -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

#ifdef __OS9NEWLINE__
#error "__OS9NEWLINE__ defined"
#endif
#if '\n' != 10
#error "wrong value in #if"
#endif

_Static_assert ('\n' == 10, "newline");
_Static_assert ('\r' == 13, "carriage return");

int el = '\l';	/* { dg-warning "unknown escape sequence" } */
