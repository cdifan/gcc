/* Calling-convention attributes without -mos9call: os9call and plain
   function types are incompatible; stackcall restates the default.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mpcrel -ma6rel" } */

typedef int (__attribute__ ((os9call)) *os9fn) (int);
typedef int (*stackfn) (int);

int __attribute__ ((os9call)) f1 (int);
int f2 (int);
int __attribute__ ((stackcall)) f3 (int);

os9fn p1 = f1;
stackfn p2 = f2;
stackfn p3 = f3;
os9fn p4 = f2;		/* { dg-warning "incompatible pointer type" } */
stackfn p5 = f1;	/* { dg-warning "incompatible pointer type" } */
os9fn p6 = f3;		/* { dg-warning "incompatible pointer type" } */
