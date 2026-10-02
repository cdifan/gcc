/* With -ma6rel, read-only structures and unions (also incomplete ones,
   whose members other translation units may not see) and volatile
   read-only variables are data, addressed relative to a6.  A read-only
   integer holding an address is data too, but only its own translation
   unit can know: it warns.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

struct ops;
extern const struct ops opaque;		/* incomplete: may hold pointers */
extern void reg (const struct ops *);
void use_opaque (void) { reg (&opaque); }

struct pt { int x, y; };
const struct pt pts[2] = { { 1, 2 }, { 3, 4 } };	/* no pointers, still data */
int get_pt (int i) { return pts[i].y; }

const volatile int cv = 1;
int get_cv (void) { return cv; }

extern int x;
const unsigned long addrtab[] = { (unsigned long) &x, 0 };	/* { dg-warning "holds an address" } */
unsigned long get_addr (int i) { return addrtab[i]; }

const int plain[] = { 1, 2 };
int get_plain (int i) { return plain[i]; }

/* { dg-final { scan-assembler "opaque\\(%a6\\)" } } */
/* { dg-final { scan-assembler "pts\\(%a6\\)|pts\\+4\\(%a6\\)" } } */
/* { dg-final { scan-assembler "cv\\(%a6\\)" } } */
/* { dg-final { scan-assembler "addrtab\\(%a6\\)" } } */
/* { dg-final { scan-assembler "\\(plain:w,%pc\\)" } } */
/* { dg-final { scan-assembler-not "\\((opaque|pts|cv|addrtab)\[^)\]*,%pc\\)" } } */
/* { dg-final { scan-assembler "\\.data\\.rel\\.ro\[^\n\]*\n(\t\\.(align|type|size)\[^\n\]*\n)*pts:" } } */
