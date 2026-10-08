/* -mos9newline maps \n to a carriage return in C strings only: in an asm
   template it stays a line feed, so that the assembler sees separate
   lines (as os9math.h's "trap #15\n\t.word 46" needs).  */
/* { dg-do assemble { target m68k-*-elfos9* } } */
/* { dg-options "-mos9newline -save-temps" } */

const char text[] = "ab\ncd";

void
f (void)
{
  __asm__ volatile ("trap #15\n\t.word 46" : : : "cc");
}

__asm__ ("\t.globl\tos9nl3\nos9nl3:\n\tnop");

/* { dg-final { scan-assembler {"ab\\rcd"} } } */
/* { dg-final { scan-assembler {trap #15\n\t\.word 46} } } */
/* { dg-final { scan-assembler {os9nl3:\n\tnop} } } */
