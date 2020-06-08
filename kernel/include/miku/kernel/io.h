#ifndef __INCLUDE_MIKU_KERNEL_IO_H
#define __INCLUDE_MIKU_KERNEL_IO_H

unsigned long virt_to_phys(void *address);

void *phys_to_virt(unsigned long address);

#endif  //__INCLUDE_MIKU_KERNEL_IO_H