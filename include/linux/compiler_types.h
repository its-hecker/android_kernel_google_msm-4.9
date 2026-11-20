/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Linux 4.9 defines compiler annotations in <linux/compiler.h>.
 * Newer KernelSU Next sources include <linux/compiler_types.h>,
 * which was introduced after this kernel version.
 *
 * Provide the newer include name without changing shared KernelSU
 * source or its pinned submodule revision.
 */
#ifndef _LINUX_COMPILER_TYPES_H
#define _LINUX_COMPILER_TYPES_H

#include <linux/compiler.h>

#endif /* _LINUX_COMPILER_TYPES_H */
