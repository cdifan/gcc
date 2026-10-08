/* -mos9newline also applies when the compiler reads preprocessed input
   (-save-temps preprocesses first, then compiles with -fpreprocessed,
   which defines no builtin macros).  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline -save-temps" } */

_Static_assert ('\n' == 13, "newline");
_Static_assert ('\l' == 10, "line feed");

const char text[] = "ab\ncd";
/* { dg-final { scan-assembler {"ab\\rcd"} } } */
