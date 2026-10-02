/* Without -mos9call, __OS9CALL__ isn't defined, but the attributes exist.  */
/* { dg-do compile } */
/* { dg-options "-mpcrel -ma6rel" } */

#ifdef __OS9CALL__
#error "__OS9CALL__ defined without -mos9call"
#endif
#if !__has_attribute (os9call) || !__has_attribute (stackcall)
#error "calling-convention attributes not supported"
#endif
int dummy;
