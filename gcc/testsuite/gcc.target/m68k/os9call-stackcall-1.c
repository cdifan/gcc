/* Under -mos9call, runtime functions keep the stack convention: GCC's
   built-in declarations, header-style declarations and K&R
   redeclarations get the stackcall attribute.  */
/* { dg-do compile } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

typedef __SIZE_TYPE__ size_t;
void *memcpy (void *, const void *, size_t);
char *malloc ();	/* { dg-warning "conflicting types for built-in" } */
size_t strlen (const char *s) { return s[0]; }

typedef void *(__attribute__ ((stackcall)) *stack_memcpy_fn) (void *, const void *, size_t);
typedef void *(*plain_memcpy_fn) (void *, const void *, size_t);
typedef size_t (__attribute__ ((stackcall)) *stack_strlen_fn) (const char *);

stack_memcpy_fn p1 = memcpy;
stack_memcpy_fn p2 = __builtin_memcpy;
plain_memcpy_fn p3 = memcpy;	/* { dg-warning "incompatible pointer type" } */
stack_strlen_fn p4 = strlen;
char *(__attribute__ ((stackcall)) *p5) () = malloc;

/* An ordinary function isn't affected.  */
int g (int);
int (*p6) (int) = g;
