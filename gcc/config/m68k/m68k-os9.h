/* override fp */
#undef FRAME_POINTER_REGNUM
#define FRAME_POINTER_REGNUM A5_REG

/* The OS-9 calling convention (-mos9call, os9call attribute) is
   available.  */
#define M68K_OS9_TARGET 1
