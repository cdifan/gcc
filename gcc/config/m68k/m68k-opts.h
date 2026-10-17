/* Definitions for option handling for Motorola 680x0/ColdFire.
   Copyright (C) 1987-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef M68K_OPTS_H
#define M68K_OPTS_H

/* Values used in the MICROARCH argument to M68K_DEVICE.  */
enum uarch_type
{
#define M68K_MICROARCH(NAME,DEVICE,MICROARCH,ISA,FLAGS) \
  u##MICROARCH,
#include "m68k-microarchs.def"
#undef M68K_MICROARCH
  ucfv5,
  unk_arch
};

/* Calling convention of the C library functions GCC knows as built-ins
   (-mbuiltin=) under -mos9call.  */
enum m68k_builtin_call
{
  M68K_BUILTIN_STACKCALL,	/* newlib */
  M68K_BUILTIN_OS9CALL		/* Microware's clib */
};

/* Where the OS-9 calling convention (-mos9call=) puts a variadic call's
   unnamed arguments.  */
enum m68k_os9call_place
{
  M68K_OS9CALL_C32,		/* like a K&R call, as Microware C 3.2 */
  M68K_OS9CALL_UCC		/* on the stack, as Ultra C */
};

/* An enumeration of all supported target devices.  */
enum target_device
{
#define M68K_DEVICE(NAME,ENUM_VALUE,FAMILY,MULTILIB,MICROARCH,ISA,FLAGS) \
  ENUM_VALUE,
#include "m68k-devices.def"
#undef M68K_DEVICE
  unk_device
};

#endif
