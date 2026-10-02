/* Without -mos9call, calls through an os9call pointer take a double
   result from d0:d1, also with -m68881.  */
/* { dg-do compile { target m68k-*-elfos9* } } */
/* { dg-options "-O2 -mpcrel -ma6rel -m68881 -fomit-frame-pointer" } */

double (__attribute__ ((os9call)) *fp) (void);
double (*plainp) (void);

double viaptr (void) { return fp () + 1.0; }
double viaplain (void) { return plainp () + 1.0; }

/* { dg-final { scan-assembler "viaptr:\n(\t\[^\n\]*\n)*\tjsr \\(%a0\\)\n\tmove.l %d1,-\\(%sp\\)\n\tmove.l %d0,-\\(%sp\\)\n\tfmove.d \\(%sp\\)\\+,%fp0" } } */
/* { dg-final { scan-assembler-not "viaplain:\n(\t\[^\n\]*\n)*\tjsr \\(%a0\\)\n\tmove.l %d1" } } */
