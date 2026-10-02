/* Frames of 32 KB or more that save only one or two integer registers,
   one of them a1: a1 is restored last (this used to ICE).  */
/* { dg-do compile } */
/* { dg-options "-O1 -mos9call -mpcrel -ma6rel -fno-omit-frame-pointer" } */

extern void use (char *);

void bigv (int a, int b) { char buf[40000]; use (buf); }

/* { dg-final { scan-assembler "move.l -?\[0-9\]+\\(%a1,%a5.l\\),%a1\n\tunlk %a5" } } */
