/* The frame pointer, a5, is also the PIC register, which -mpcrel (it
   sets flag_pic) doesn't use: link saves it, and it is not saved again
   in functions that save all registers or use the constant pool.  The
   second save, with the frame's own value, made the unwind information
   give that value to the caller.
   fixed: f5acd3f108 2026-10-29 m68k: the OS-9 frame pointer is not saved again as the PIC register
*/
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -fno-omit-frame-pointer -mpcrel -ma6rel" } */

extern void g (void *);
extern void k (long double);

/* All registers saved: d2-d7 and a2-a4 (a6 is fixed, link saves a5).  */
void
all_regs (void)
{
  char buf[8];
  __builtin_unwind_init ();
  g (buf);
}

/* The long double constant is in the constant pool.  */
void
const_pool (void)
{
  char buf[8];
  g (buf);
  k (1.2345678901234567L);
}

/* { dg-final { scan-assembler "movem.l #16184,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler-not "movem.l #16188,-\\(%sp\\)" } } */
/* { dg-final { scan-assembler-not "move.l %a5,-\\(%sp\\)" } } */
