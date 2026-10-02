/* OS-9 convention, caller side: 8-byte scalars as argument 1 go in
   d0:d1, otherwise on the stack; after a double first argument, or a
   double second argument, everything else goes on the stack.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

extern void fd (double);
extern void fdi (double, int);
extern void fid (int, double, int);
extern void fll (long long, int);
extern void fill (int, long long);

void td (void) { fd (1.5); }
void tdi (void) { fdi (2.5, 2222); }
void tid (void) { fid (3331, 3.5, 3333); }
void tll (void) { fll (0x123456789LL, 4442); }
void till (void) { fill (5551, 0x987654321LL); }

/* 1.5 = 0x3FF80000 00000000, 2.5 = 0x40040000 0, 3.5 = 0x400C0000 0.  */
/* { dg-final { scan-assembler "move.l #1073217536,%d0\n\tclr.l %d1" } } */
/* { dg-final { scan-assembler "pea 2222.w\n\tmove.l #1074003968,%d0\n\tclr.l %d1" } } */
/* { dg-final { scan-assembler "pea 3333.w\n\tclr.l -\\(%sp\\)\n\tmove.l #1074528256,-\\(%sp\\)\n\tmove.l #3331,%d0\n\tlea" } } */
/* { dg-final { scan-assembler "pea 4442.w\n\tmoveq #1,%d0\n\tmove.l #591751049,%d1" } } */
/* { dg-final { scan-assembler "move.l #-2023406815,-\\(%sp\\)\n\tpea 9.w\n\tmove.l #5551,%d0\n\tlea" } } */
