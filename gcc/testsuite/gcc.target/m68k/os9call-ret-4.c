/* Calls through pointers to OS-9 convention functions take float and
   double results from d0 and d0:d1, also with -m68881.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mos9call -mpcrel -ma6rel -m68881 -fomit-frame-pointer -w" } */

double (*fp) (void);
float (*fq) (void);

double viaptr (void) { return fp () + 1.0; }
float viaptrf (void) { return fq () * 2.0f; }

/* { dg-final { scan-assembler "viaptr:\n(\t\[^\n\]*\n)*\tjsr \\(%a0\\)\n\tmove.l %d1,-\\(%sp\\)\n\tmove.l %d0,-\\(%sp\\)\n\tfmove.d \\(%sp\\)\\+,%fp0" } } */
/* { dg-final { scan-assembler "viaptrf:\n(\t\[^\n\]*\n)*\tjsr \\(%a0\\)\n\tfmove.s %d0,%fp0" } } */
