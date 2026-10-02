/* OS-9 convention, caller side: argument 1 in d0, argument 2 in d1 if
   argument 1 used d0 alone, the rest on the stack.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

extern void f1 (int);
extern void f2 (int, int);
extern void f3 (int, int, int);
extern void fp (char *, int);
extern void fc (char, short);
extern void ff (float, int);
extern void (*fptr) (int, int);

void t1 (void) { f1 (1111); }
void t2 (void) { f2 (2221, 2222); }
void t3 (void) { f3 (3331, 3332, 3333); }
void tp (char *p) { fp (p, 4442); }
void tc (void) { fc (65, 5552); }
void tf (void) { ff (1.5f, 6662); }
void ti (void) { fptr (7771, 7772); }

/* { dg-final { scan-assembler "move.l #1111,%d0" } } */
/* { dg-final { scan-assembler "move.l #2221,%d0" } } */
/* { dg-final { scan-assembler "move.l #2222,%d1" } } */
/* { dg-final { scan-assembler "move.l #3331,%d0" } } */
/* { dg-final { scan-assembler "move.l #3332,%d1" } } */
/* { dg-final { scan-assembler "pea 3333.w" } } */
/* { dg-final { scan-assembler "move.l #4442,%d1" } } */
/* { dg-final { scan-assembler "moveq #65,%d0" } } */
/* { dg-final { scan-assembler "move.l #5552,%d1" } } */
/* { dg-final { scan-assembler "move.l #0x3fc00000,%d0" } } */
/* { dg-final { scan-assembler "move.l #6662,%d1" } } */
/* { dg-final { scan-assembler "move.l #7771,%d0" } } */
/* { dg-final { scan-assembler "move.l #7772,%d1" } } */
/* { dg-final { scan-assembler-not "pea (1111|2221|2222|3331|3332|4442|5552|6662|7771|7772)" } } */
