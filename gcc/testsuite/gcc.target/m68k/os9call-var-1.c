/* OS-9 convention: variadic calls are placed like unprototyped (K&R)
   calls, with the usual promotions of unnamed arguments.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

extern void v1 (int, ...);
extern void v2 (int, int, ...);
extern void k ();

void t1 (void) { v1 (1111, 1112, 1113); }
void t2 (void) { v1 (2221, 2.5); }
void t3 (void) { v2 (3331, 3332, 3333); }
void t4 (void) { v1 (4441, (char) 65, (float) 1.5f); }
void t5 (void) { k (5551, 5552, 5553); }

/* { dg-final { scan-assembler "pea 1113.w\n\tmove.l #1112,%d1\n\tmove.l #1111,%d0" } } */
/* { dg-final { scan-assembler "clr.l -\\(%sp\\)\n\tmove.l #1074003968,-\\(%sp\\)\n\tmove.l #2221,%d0" } } */
/* { dg-final { scan-assembler "pea 3333.w\n\tmove.l #3332,%d1\n\tmove.l #3331,%d0" } } */
/* The float is promoted to double (1.5 = 0x3FF80000 0) and pushed.  */
/* { dg-final { scan-assembler "clr.l -\\(%sp\\)\n\tmove.l #1073217536,-\\(%sp\\)\n\tmoveq #65,%d1\n\tmove.l #4441,%d0" } } */
/* { dg-final { scan-assembler "pea 5553.w\n\tmove.l #5552,%d1\n\tmove.l #5551,%d0" } } */
