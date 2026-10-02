/* Calling-convention attributes under -mos9call: os9call restates the
   default; stackcall and plain function types are incompatible.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9call -mpcrel -ma6rel" } */

typedef int (__attribute__ ((os9call)) *os9fn) (int);
typedef int (__attribute__ ((stackcall)) *stackfn) (int);
typedef int (*plainfn) (int);

int __attribute__ ((os9call)) f1 (int);
int f2 (int);
int __attribute__ ((stackcall)) f3 (int);

os9fn p1 = f1;
os9fn p2 = f2;
plainfn p3 = f1;
stackfn p4 = f3;
plainfn p5 = f3;	/* { dg-warning "incompatible pointer type" } */
stackfn p6 = f2;	/* { dg-warning "incompatible pointer type" } */
