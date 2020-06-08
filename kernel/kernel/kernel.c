#include <miku/arch/i386/io.h>
#include <miku/kernel/io.h>
#include <miku/kernel/panic.h>
#include <miku/kernel/printk.h>
#include <miku/kernel/tty.h>
#include <stdint.h>

#include "multiboot.h"

#ifdef __i386__
#include <miku/arch/i386/gdt.h>
#endif

void kernel_main(unsigned long magic, multiboot_info_t* boot_info_phys) {
    (void)magic;
    terminal_initialize();
    printk("kernal virt start: %p\n", KERNEL_START_VIRT_ADDR);
    printk("kernel virt end: %p\n", KERNEL_END_VIRT_ADDR);
    multiboot_info_t* boot_info = phys_to_virt((unsigned long)boot_info_phys);
    printk("boot_info_phys: %p\n", boot_info_phys);
    printk("boot_info: %p\n", boot_info);

    printk("kernel_main address: %p\n", &kernel_main);

    // getting memory map from multiboot_info
    if (boot_info->flags & 1) {
        printk("mem_lower: %lu, mem_upper: %lu\n", boot_info->mem_lower, boot_info->mem_upper);
    }
#ifdef __i386__
    printk("GDT entries:\n");
    for (int i = 0; i < N_GDT_ENTRIES; i++) {
        printk("\t%d: 0x%016llX\n", i, gdt[i]);
    }
#endif
}