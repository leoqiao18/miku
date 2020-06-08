#ifndef __INCLUDE_ARCH_I386_IO_H
#define __INCLUDE_ARCH_I386_IO_H

#include <miku/arch/i386/kernel_layout.h>

#define KERNEL_VIRT_TO_PHYS(address) ((unsigned long)(address)-KERNEL_VIRT_MEM_OFFSET)
#define KERNEL_PHYS_TO_VIRT(address) ((void *)((address) + KERNEL_VIRT_MEM_OFFSET))

unsigned long __kernel_virt_to_phys(void *address);

void *__kernel_phys_to_virt(unsigned long address);

#endif  //__INCLUDE_ARCH_I386_IO_H