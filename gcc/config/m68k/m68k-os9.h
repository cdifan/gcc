/* override fp */
#undef FRAME_POINTER_REGNUM
#define FRAME_POINTER_REGNUM A5_REG

/* The OS-9 calling convention (-mos9call, os9call attribute) is
   available.  */
#define M68K_OS9_TARGET 1

/* The macros Microware C defines for OS-9/68K, so that code and headers
   written for it (Microware's own stdio.h tests OSK) see the same: its
   preprocessor defines OSK (and mc68000, which m68k.h does), and its cc
   driver _OSK, _MPF68K and _BIG_END, with _MPF68020 or _MPFCPU32 for those
   processors and _FPF881 for the 68881.  OSK, like mc68000, also as __OSK
   and __OSK__, and only those in strict ISO C.  The CPU32 has the 68020
   ISA flag, but not CAS.  */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()			\
  do							\
    {							\
      builtin_define ("__embedded__");			\
      builtin_define_std ("OSK");			\
      builtin_define ("_OSK");				\
      builtin_define ("_MPF68K");			\
      builtin_define ("_BIG_END");			\
      if (TARGET_68020 && TARGET_CAS)			\
	builtin_define ("_MPF68020");			\
      else if (TARGET_68020)				\
	builtin_define ("_MPFCPU32");			\
      if (TARGET_68881)					\
	builtin_define ("_FPF881");			\
    }							\
  while (0)

/* -mos9math: libos9math (newlib's libgloss) goes before libgcc, so its
   versions of the soft-float routines, through OS-9's math module, are
   the ones used, also by the C library (hence after it too).  */
#undef LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC \
  "%{mos9math:-los9math} %G %{!nolibc:%L %{mos9math:-los9math} %G}"
