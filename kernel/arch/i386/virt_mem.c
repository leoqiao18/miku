#include <miku/arch/i386/io.h>
#include <miku/arch/i386/kernel_layout.h>
#include <miku/kernel/io.h>
#include <miku/kernel/printk.h>

unsigned long __kernel_virt_to_phys(void *address) {
    return KERNEL_VIRT_TO_PHYS(address);
}

void *__kernel_phys_to_virt(unsigned long address) {
    return KERNEL_PHYS_TO_VIRT(address);
}

unsigned long virt_to_phys(void *address) {
    if (KERNEL_START_VIRT_ADDR <= address && address < KERNEL_END_VIRT_ADDR) {
        return __kernel_virt_to_phys(address);
    }

    // TODO
    return (unsigned long)address;
}

void *phys_to_virt(unsigned long address) {
    if (KERNEL_START_PHYS_ADDR <= address && address < KERNEL_END_PHYS_ADDR) {
        return __kernel_phys_to_virt(address);
    }

    //TODO
    return (void *)0;
}