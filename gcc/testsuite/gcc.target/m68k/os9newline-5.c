/* -mos9newline=swapped: \n a carriage return and \r a line feed, as in
   Microware Ultra C's strict ANSI mode; \l is no escape there.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline=swapped" } */

#if __OS9NEWLINE__ != 2
#error "__OS9NEWLINE__ not 2"
#endif
#if '\n' != 13 || '\r' != 10
#error "wrong values in #if"
#endif

_Static_assert ('\n' == 13, "newline");
_Static_assert ('\r' == 10, "carriage return escape");
_Static_assert (L'\r' == 10, "wide carriage return escape");

int el = '\l';	/* { dg-warning "unknown escape sequence" } */

/* The bytes: 13 for \n, 10 for \r (written as \r and \n by GCC).  */
const char text[] = "a\nb\rc";
/* { dg-final { scan-assembler {"a\\rb\\nc"} } } */
/* \l is the letter l, 108.  */
/* { dg-final { scan-assembler {el:\s+\.long\s+108} } } */
