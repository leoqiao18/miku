#ifndef __INCLUDE_MIKU_KERNEL_MEM_H
#define __INCLUDE_MIKU_KERNEL_MEM_H

#include <miku/kernel/multiboot.h>

void mem_init(multiboot_info_t *bootinfo);

unsigned long virt_to_phys(void *address);

void *phys_to_virt(unsigned long address);

#endif  //__INCLUDE_MIKU_KERNEL_MEM_H