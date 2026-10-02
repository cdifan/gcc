/* OS-9 convention, caller side: aggregates, long double and complex
   values always go on the stack, and a struct as argument 1 leaves d0
   and d1 unused.  Structs smaller than 4 bytes sit at the start of
   their 4-byte slot, as in Microware C.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

struct s1 { char c; };
struct s2 { char a, b; };
struct s3 { char a, b, c; };
struct s4 { int i; };
struct s12 { int a, b, c; };
extern void fs1 (struct s1, int);
extern void fs2 (struct s2, int);
extern void fs3 (struct s3, int);
extern void fs4 (struct s4, int);
extern void fs12 (struct s12, int);
extern void fld (long double, int);
extern void fcx (_Complex float, int);

void ts1 (struct s1 *p) { fs1 (*p, 1112); }
void ts2 (struct s2 *p) { fs2 (*p, 2222); }
void ts3 (struct s3 *p) { fs3 (*p, 3332); }
void ts4 (struct s4 *p) { fs4 (*p, 4442); }
void ts12 (struct s12 *p) { fs12 (*p, 5552); }
void tld (long double x) { fld (x, 6662); }
void tcx (_Complex float x) { fcx (x, 7772); }

/* { dg-final { scan-assembler "pea 1112.w\n\tsubq.l #4,%sp\n\tmove.l %d0,%a0\n\tmove.b \\(%a0\\),\\(%sp\\)\n" } } */
/* { dg-final { scan-assembler "pea 2222.w\n\tsubq.l #4,%sp\n\tmove.b \\(%a0\\),\\(%sp\\)\n\tmove.b 1\\(%a0\\),1\\(%sp\\)\n" } } */
/* { dg-final { scan-assembler "pea 3332.w\n\tsubq.l #4,%sp\n\tmove.l %d0,%a0\n\tmove.l %sp,%a1\n" } } */
/* { dg-final { scan-assembler "pea 4442.w\n\tmove.l %d0,%a0\n\tmove.l \\(%a0\\),-\\(%sp\\)\n" } } */
/* { dg-final { scan-assembler "pea 5552.w" } } */
/* { dg-final { scan-assembler "pea 6662.w" } } */
/* { dg-final { scan-assembler "pea 7772.w" } } */
/* { dg-final { scan-assembler-not "#\[0-9\]+,%d\[01\]" } } */
