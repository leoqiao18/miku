#include <miku/arch/i386/io.h>
#include <miku/arch/i386/kernel_layout.h>
#include <miku/kernel/io.h>

unsigned long __kernel_virt_to_phys(void *address) {
    return KERNEL_VIRT_TO_PHYS(address);
}

void *__kernel_phys_to_virt(unsigned long address) {
    return KERNEL_PHYS_TO_VIRT(address);
}

unsigned long virt_to_phys(void *address) {
    if (_kernel_start <= address && address < _kernel_end) {
        return __kernel_virt_to_phys(address);
    }

    // TODO
    return (unsigned long)address;
}

void *phys_to_virt(unsigned long address) {
    if (_kernel_start - KERNEL_VIRT_MEM_OFFSET <= (void *)address && (void *)address < _kernel_end) {
        return __kernel_phys_to_virt(address);
    }
    return (void *)0;
}