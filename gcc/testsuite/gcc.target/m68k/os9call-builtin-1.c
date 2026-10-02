/* -mbuiltin=os9call (Microware's clib): memcpy for a struct copy and
   explicit calls to strlen, malloc and free use the OS-9 convention;
   libgcc helpers and complex arithmetic keep the stack convention.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mbuiltin=os9call -mpcrel -ma6rel" } */

typedef __SIZE_TYPE__ size_t;
extern size_t strlen (const char *);
extern void *malloc (size_t);
char *malloc_kr ();
struct big { int a[100]; };

void copy (struct big *d, struct big *s) { *d = *s; }
size_t len (const char *s) { return strlen (s); }
void *alloc (void) { return malloc (1111); }
long long mul (long long a, long long b) { return a * b; }
_Complex float cm (_Complex float a, _Complex float b) { return a * b; }

/* { dg-final { scan-assembler "pea 400.w\n(\t\[^\n\]*\n)*\tlea \\(memcpy" } } */
/* { dg-final { scan-assembler-not "move.l %d0,-\\(%sp\\)\n\tlea \\(memcpy" } } */
/* { dg-final { scan-assembler "len:\n(\t\[^\n\]*\n)*\tlea \\(strlen:w,%pc\\),%a\[01\]\n\tjsr" } } */
/* { dg-final { scan-assembler-not "move.l %d0,-\\(%sp\\)\n\tlea \\(strlen" } } */
/* { dg-final { scan-assembler "move.l #1111,%d0\n\tlea \\(malloc" } } */
/* { dg-final { scan-assembler "__muldi3" } } */
/* { dg-final { scan-assembler "lea \\(__mulsc3:w,%pc\\)" } } */
