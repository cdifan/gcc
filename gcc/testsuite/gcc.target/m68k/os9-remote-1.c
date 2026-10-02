/* The remote attribute: variables in .remote.data / .remote.bss (the
   latter without contents), addressed as a6 plus a 32-bit offset
   (move.l #sym).  Normal variables stay a6-relative.  */
/* { dg-do compile } */
/* { dg-options "-O2 -mpcrel -ma6rel -fno-common" } */

char big[70000] __attribute__ ((remote));
int rinit[4] __attribute__ ((remote)) = { 1, 2, 3, 4 };
int normal;

int get (int i) { return big[i] + rinit[1] + normal; }
int *addr (void) { return &rinit[2]; }

/* { dg-final { scan-assembler "\\.section\t\\.remote\\.bss,\"aw\",@nobits" } } */
/* { dg-final { scan-assembler "\\.section\t\\.remote\\.data,\"aw\"" } } */
/* { dg-final { scan-assembler "move.l #big,%a0\n\tadd.l %a6,%a0" } } */
/* { dg-final { scan-assembler "move.l #rinit,%d0\n\tmove.l 4\\(%a6,%d0.l\\),%d0" } } */
/* { dg-final { scan-assembler "move.l #rinit\\+8,%d0\n\tadd.l %a6,%d0" } } */
/* { dg-final { scan-assembler "add.l normal\\(%a6\\),%d0" } } */
/* { dg-final { scan-assembler-not "(big|rinit)\[^\n\]*\\(%a6\\)" } } */
