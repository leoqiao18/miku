#include <miku/arch/i386/mem.h>
#include <miku/kernel/mem.h>
#include <miku/kernel/multiboot.h>
#include <miku/kernel/panic.h>
#include <miku/kernel/printk.h>
#include <miku/kernel/tty.h>
#include <stdint.h>

#ifdef __i386__
#include <miku/arch/i386/gdt.h>
#endif

static multiboot_info_t* bootinfo;

void kernel_main(unsigned long magic, multiboot_info_t* bootinfo_phys) {
    // multiboot
    (void)magic;
    bootinfo = phys_to_virt((unsigned long)bootinfo_phys);

    // terminal
    terminal_init(bootinfo);
    mem_init(bootinfo);

    // global descriptor table
#ifdef __i386__
    printk("GDT entries:\n");
    for (int i = 0; i < N_GDT_ENTRIES; i++) {
        printk("\t%d: 0x%016llX\n", i, gdt[i]);
    }
#endif

    // print kernel memory addresses
    printk("kernal virt start: %p\n", KERNEL_START_VIRT_ADDR);
    printk("kernel virt end: %p\n", KERNEL_END_VIRT_ADDR);
    printk("kernel_main address: %p\n", &kernel_main);
}