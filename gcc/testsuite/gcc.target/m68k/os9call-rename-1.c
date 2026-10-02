/* Register renaming (-frename-registers, also on with -funroll-loops)
   runs after the prologue: it must not move values into registers an
   OS-9 convention function didn't save.  An unprototyped function has
   the default ABI, which counts a1 as clobbered.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -frename-registers -mpcrel -ma6rel -mos9call" } */

int v;
char *f () { return v == 0 ? "" : "abc"; }

/* { dg-final { scan-assembler-not "%a1" } } */
