/*
 * Copyright (c) 2010-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Kernel structure member offset definition file
 *
 * This module is responsible for the generation of the absolute symbols whose
 * value represents the member offsets for various IA-32 structures.
 *
 * All of the absolute symbols defined by this module will be present in the
 * final kernel ELF image (due to the linker's reference to the _OffsetAbsSyms
 * symbol).
 *
 * INTERNAL
 * It is NOT necessary to define the offset for every member of a structure.
 * Typically, only those members that are accessed by assembly language routines
 * are defined; however, it doesn't hurt to define all fields for the sake of
 * completeness.
 */

#include <gen_offset.h> /* located in kernel/include */

/* list of headers that define whose structure offsets will be generated */

#include <kernel_structs.h>
#include <ia32/mmustructs.h>
#include <arch/x86/multiboot.h>

#include <kernel_offsets.h>

#if defined(CONFIG_LAZY_FP_SHARING)
GEN_OFFSET_SYM(_thread_arch_t, excNestCount);
#endif

GEN_OFFSET_SYM(_thread_arch_t, preempFloatReg);

/**
 * size of the struct k_thread structure sans save area for floating
 * point regs
 */

GEN_ABSOLUTE_SYM(_K_THREAD_NO_FLOAT_SIZEOF,
		 sizeof(struct k_thread) - sizeof(tPreempFloatReg));

GEN_OFFSET_SYM(_callee_saved_t, esp);

/* z_arch_esf_t structure member offsets */

GEN_OFFSET_SYM(z_arch_esf_t, esp);
GEN_OFFSET_SYM(z_arch_esf_t, ebp);
GEN_OFFSET_SYM(z_arch_esf_t, ebx);
GEN_OFFSET_SYM(z_arch_esf_t, esi);
GEN_OFFSET_SYM(z_arch_esf_t, edi);
GEN_OFFSET_SYM(z_arch_esf_t, edx);
GEN_OFFSET_SYM(z_arch_esf_t, ecx);
GEN_OFFSET_SYM(z_arch_esf_t, eax);
GEN_OFFSET_SYM(z_arch_esf_t, errorCode);
GEN_OFFSET_SYM(z_arch_esf_t, eip);
GEN_OFFSET_SYM(z_arch_esf_t, cs);
GEN_OFFSET_SYM(z_arch_esf_t, eflags);

/* tTaskStateSegment structure member offsets */


/* size of the MMU_REGION structure. Used by linker scripts */

GEN_ABSOLUTE_SYM(__MMU_REGION_SIZEOF, sizeof(struct mmu_region));

/* size of struct x86_multiboot_info, used by crt0.S */

GEN_ABSOLUTE_SYM(__X86_MULTIBOOT_INFO_SIZEOF,
	sizeof(struct x86_multiboot_info));

GEN_ABS_SYM_END
