/* With a frame of 32 KB or more, the epilogue may use a1 as an index
   register; under the OS-9 convention a1 is saved and the registers are
   restored with movem, which computes the address before loading a1.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fno-omit-frame-pointer" } */

extern void __attribute__ ((stackcall)) clobber (void);
extern void use (char *);

int
big (int a)
{
  char buf[40000];
  use (buf);
  return a;
}

/* { dg-final { scan-assembler "movem.l -?\[0-9\]+\\(%a1,%a5.l\\),#\[0-9\]+" } } */
/* { dg-final { scan-assembler-not "move.l -?\[0-9\]+\\(%a1,%a5.l\\)," } } */
