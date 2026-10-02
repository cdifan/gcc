/* OS-9 convention, return values: float in d0, double in d0:d1;
   aggregates (of any size), long double and complex values in memory,
   at the address the caller passes in a0.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -fomit-frame-pointer" } */

struct s1 { char c; };
struct s3i { int a, b, c; };
extern struct s3i gs (int);

float rf (void) { return 1.5f; }
struct s1 r1 (int x) { struct s1 r = { x }; return r; }
int cs (void) { struct s3i s = gs (7); return s.b; }
_Complex float rcx (_Complex float x) { return x; }

/* { dg-final { scan-assembler "rf:\n\tmove.l #0x3fc00000,%d0\n\trts" } } */
/* r1: the 1-byte struct is stored through a0, which is preserved.  */
/* { dg-final { scan-assembler "r1:\n\tmove.l %a0,-\\(%sp\\)\n\tmove.b %d0,\\(%a0\\)" } } */
/* cs: the caller passes the buffer address in a0.  */
/* { dg-final { scan-assembler "lea \\(12,%sp\\),%a0\n\tmoveq #7,%d0\n\tlea \\(gs:w,%pc\\),%a1\n\tjsr \\(%a1\\)" } } */
/* { dg-final { scan-assembler "rcx:\n\tmove.l %a0,-\\(%sp\\)\n\tmove.l 8\\(%sp\\),\\(%a0\\)" } } */
