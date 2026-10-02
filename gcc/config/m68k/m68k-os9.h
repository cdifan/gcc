/* override fp */
#undef FRAME_POINTER_REGNUM
#define FRAME_POINTER_REGNUM A5_REG

/* Under the OS-9 calling convention, float and double values are
   returned in d0 and d0:d1 even with -m68881.  */
#undef FUNCTION_VALUE
#define FUNCTION_VALUE(VALTYPE, FUNC) m68k_os9_function_value (VALTYPE, FUNC)
