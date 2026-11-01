/* At -O0 the OS-9 target makes a jump table for a dense switch, as
   Microware C and GCC 11 do: GCC 16 enables jump tables only from -O1 on,
   and a chain of compares was larger.
   fixed: 2026-11-01 m68k: OS-9 jump tables and bit tests at -O0 too
*/
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O0 -mpcrel -ma6rel" } */

extern void g (int);

void
f (int x)
{
  switch (x)
    {
    case 0: g (10); break;
    case 1: g (11); break;
    case 2: g (12); break;
    case 3: g (13); break;
    case 4: g (14); break;
    case 5: g (15); break;
    case 6: g (16); break;
    }
}

/* { dg-final { scan-assembler "jmp %pc@\\(2,%d0:w\\)" } } */
/* { dg-final { scan-assembler-times "\\.word \\.L\[0-9\]+-\\.L\[0-9\]+" 7 } } */
