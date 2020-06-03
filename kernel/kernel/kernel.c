#include <miku/kernel/tty.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __i386__
#include <miku/arch/i386/gdt.h>
#endif

extern char g_length;

void kernel_main(void) {
    terminal_initialize();
#ifdef __i386__
    printf("GDT entries:\n");
    for (int i = 0; i < N_GDT_ENTRIES; i++) {
        printf("\t%d: 0x%llX\n", i, gdt[i]);
    }
#endif
}