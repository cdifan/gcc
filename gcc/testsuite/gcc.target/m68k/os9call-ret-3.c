/* Without -mos9call, only os9call functions return small structs in
   memory and doubles in d0:d1 with -m68881.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel -m68881 -fomit-frame-pointer" } */

struct s4 { int i; };

struct s4 __attribute__ ((os9call)) mw (int x) { struct s4 r = { x }; return r; }
struct s4 plain (int x) { struct s4 r = { x }; return r; }
double __attribute__ ((os9call)) mwd (void) { return 2.5; }
double plaind (void) { return 2.5; }

/* { dg-final { scan-assembler "mw:\n\tmove.l %a0,-\\(%sp\\)\n\tmove.l %d0,\\(%a0\\)" } } */
/* { dg-final { scan-assembler "plain:\n\tmove.l 4\\(%sp\\),%d0\n\trts" } } */
/* { dg-final { scan-assembler "mwd:\n\tmove.l #1074003968,%d0\n\tclr.l %d1\n\trts" } } */
/* { dg-final { scan-assembler "plaind:\n\tfmove.d #0x4004000000000000,%fp0\n\trts" } } */
