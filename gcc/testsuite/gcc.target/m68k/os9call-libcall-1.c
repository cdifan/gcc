/* Under -mos9call, runtime functions keep the stack convention: memcpy
   for a struct copy, explicit calls to strlen, malloc and free, and
   libgcc helpers (libcalls).  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel" } */

typedef __SIZE_TYPE__ size_t;
extern size_t strlen (const char *);
extern void *malloc (size_t);
extern void free (void *);
struct big { int a[100]; };

void copy (struct big *d, struct big *s) { *d = *s; }
size_t len (const char *s) { return strlen (s); }
void *alloc (void) { return malloc (1111); }
void rel (void *p) { free (p); }
long long mul (long long a, long long b) { return a * b; }

/* { dg-final { scan-assembler "pea 400.w\n\tmove.l %d1,-\\(%sp\\)\n\tmove.l %d0,-\\(%sp\\)\n\tlea \\(memcpy" } } */
/* { dg-final { scan-assembler "move.l %d0,-\\(%sp\\)\n\tlea \\(strlen" } } */
/* { dg-final { scan-assembler "pea 1111.w\n\tlea \\(malloc" } } */
/* { dg-final { scan-assembler "move.l %d0,-\\(%sp\\)\n\tlea \\(free" } } */
/* { dg-final { scan-assembler "__muldi3" } } */
