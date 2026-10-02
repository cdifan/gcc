/* With -ma6rel, read-only variables that hold addresses are data,
   addressed relative to a6 and placed in a writable data section: OS-9
   only relocates addresses in the initialized data.  Other read-only
   variables stay in the code area, addressed PC-relative.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

const char *const tbl[] = { "a", "b" };
const char *const nul[] = { 0, 0 };	/* no relocations, still data */
const int plain[] = { 1, 2 };
extern const struct s { int n; const char *p; } ext;	/* by its type */

const char *f (int i) { return tbl[i]; }
const char *g (int i) { return nul[i]; }
int h (int i) { return plain[i]; }
const char *k (void) { return ext.p; }

/* { dg-final { scan-assembler "tbl\\(%a6\\)" } } */
/* { dg-final { scan-assembler "nul\\(%a6\\)" } } */
/* { dg-final { scan-assembler "ext\\+4\\(%a6\\)" } } */
/* { dg-final { scan-assembler "\\(plain:w,%pc\\)" } } */
/* { dg-final { scan-assembler-not "\\((tbl|nul|ext)\[^)\]*,%pc\\)" } } */
/* Each variable in its section, possibly after .align, .type, .size.  */
/* { dg-final { scan-assembler "\\.data\\.rel\\.ro\[^\n\]*\n(\t\\.(align|type|size)\[^\n\]*\n)*tbl:" } } */
/* { dg-final { scan-assembler "\\.data\\.rel\\.ro\[^\n\]*\n(\t\\.(align|type|size)\[^\n\]*\n)*nul:" } } */
/* { dg-final { scan-assembler "\\.rodata\n(\t\\.(align|type|size)\[^\n\]*\n)*plain:" } } */
