/* -mos9regfunc accepts register only on a function declaration in a
   block: at file scope it stays an error.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-mos9regfunc" } */

register int f (void); /* { dg-error "invalid storage class for function .f." } */
