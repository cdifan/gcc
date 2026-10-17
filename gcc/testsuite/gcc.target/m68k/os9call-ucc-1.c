/* -mos9call=ucc: a variadic call's unnamed arguments always go on the
   stack, as Ultra C places them; named arguments, and the arguments of
   unprototyped calls, are placed as with -mos9call.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call=ucc -mpcrel -ma6rel" } */

extern void v1 (int, ...);
extern void v2 (int, int, ...);
extern void k ();
extern void p3 (int, int, int);

void t1 (void) { v1 (1111, 1112, 1113); }
void t2 (void) { v1 (2221, 2.5); }
void t3 (void) { v2 (3331, 3332, 3333); }
void t4 (void) { v1 (4441, (char) 65, (float) 1.5f); }
void t5 (void) { k (5551, 5552, 5553); }
void t6 (void) { p3 (6661, 6662, 6663); }

/* { dg-final { scan-assembler "pea 1113.w\n\tpea 1112.w\n\tmove.l #1111,%d0" } } */
/* { dg-final { scan-assembler "clr.l -\\(%sp\\)\n\tmove.l #1074003968,-\\(%sp\\)\n\tmove.l #2221,%d0" } } */
/* { dg-final { scan-assembler "pea 3333.w\n\tmove.l #3332,%d1\n\tmove.l #3331,%d0" } } */
/* The float is promoted to double (1.5 = 0x3FF80000 0) and pushed, the
   char promoted to int and pushed.  */
/* { dg-final { scan-assembler "clr.l -\\(%sp\\)\n\tmove.l #1073217536,-\\(%sp\\)\n\tpea 65.w\n\tmove.l #4441,%d0" } } */
/* { dg-final { scan-assembler "pea 5553.w\n\tmove.l #5552,%d1\n\tmove.l #5551,%d0" } } */
/* { dg-final { scan-assembler "pea 6663.w\n\tmove.l #6662,%d1\n\tmove.l #6661,%d0" } } */
