/* Without -mos9call: os9call functions use the OS-9 convention, all
   others the stack convention.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

extern int __attribute__ ((os9call)) mw (int, int, int);
extern int plain (int, int, int);
typedef int (__attribute__ ((os9call)) *mwfn) (int, int);

int t1 (void) { return mw (1111, 1112, 1113); }
int t2 (void) { return plain (2221, 2222, 2223); }
int t3 (mwfn f) { return f (3331, 3332); }
int __attribute__ ((os9call)) cb (int a, int b) { return b; }

/* { dg-final { scan-assembler "pea 1113.w\n\tmove.l #1112,%d1\n\tmove.l #1111,%d0" } } */
/* { dg-final { scan-assembler "pea 2223.w\n\tpea 2222.w\n\tpea 2221.w" } } */
/* { dg-final { scan-assembler "move.l #3332,%d1\n\tmove.l #3331,%d0" } } */
/* { dg-final { scan-assembler "cb:\n\tmove.l %d1,%d0\n\trts" } } */
