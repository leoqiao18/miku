#ifndef __INCLUDE_ARCH_I386_KERNEL_LAYOUT_H
#define __INCLUDE_ARCH_I386_KERNEL_LAYOUT_H

#define KERNEL_VIRT_MEM_OFFSET 0xC0000000

/* kernel addresses boundaries */
extern char _kernel_start[];
extern char _kernel_end[];
// #define KERNEL_START_VIRT_ADDR ((void *)_kernel_start)
#define KERNEL_START_VIRT_ADDR ((void *)KERNEL_VIRT_MEM_OFFSET)  // TODO: also includes stuff before the kernel
#define KERNEL_END_VIRT_ADDR ((void *)_kernel_end)
#define KERNEL_START_PHYS_ADDR ((unsigned long)KERNEL_START_VIRT_ADDR - KERNEL_VIRT_MEM_OFFSET)
#define KERNEL_END_PHYS_ADDR ((unsigned long)KERNEL_END_VIRT_ADDR - KERNEL_VIRT_MEM_OFFSET)

/* VGA memory */
#define VGA_PHYS_ADDR ((void *)0xB8000)
#define VGA_VIRT_ADDR ((void *)(((unsigned long)VGA_PHYS_ADDR) + KERNEL_VIRT_MEM_OFFSET))

#endif  //__INCLUDE_ARCH_I386_KERNEL_LAYOUT_H