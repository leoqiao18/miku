#ifndef __INCLUDE_ARCH_I386_KERNEL_LAYOUT_H
#define __INCLUDE_ARCH_I386_KERNEL_LAYOUT_H

#define KERNEL_VIRT_MEM_OFFSET 0xC0000000

/* virtual addresses */
extern void *_kernel_start;
extern void *_kernel_end;

#endif  //__INCLUDE_ARCH_I386_KERNEL_LAYOUT_H