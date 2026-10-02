/* A struct smaller than 4 bytes can't be passed by value to a function
   whose convention differs from the -mos9call setting.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel" } */

struct s1 { char c; };
struct s4 { int i; };
extern void __attribute__ ((os9call)) f1 (struct s1);
extern void __attribute__ ((os9call)) f4 (struct s4);
void t1 (struct s1 *p) { f1 (*p); }	/* { dg-error "smaller than 4 bytes" } */
void t4 (struct s4 *p) { f4 (*p); }
