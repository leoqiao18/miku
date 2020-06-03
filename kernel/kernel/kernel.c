#include <miku/kernel/panic.h>
#include <miku/kernel/printk.h>
#include <miku/kernel/tty.h>
#include <stdint.h>

#ifdef __i386__
#include <miku/arch/i386/gdt.h>
#endif

extern char g_length;

void kernel_main(void) {
    terminal_initialize();
#ifdef __i386__
    printk("GDT entries:\n");
    for (int i = 0; i < N_GDT_ENTRIES; i++) {
        printk("\t%d: 0x%016llX\n", i, gdt[i]);
    }
#endif
    panic("error...");
}