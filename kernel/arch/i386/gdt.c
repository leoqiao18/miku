#include <miku/arch/i386/gdt.h>

uint64_t gdt[N_GDT_ENTRIES];
uint16_t gdt_size_minus_one = sizeof(gdt) - 1;

void gdt_init() {
    gdt[0] = create_gdt_entry(0, 0, 0);
    gdt[1] = create_gdt_entry(0, 0x000FFFFF, (GDT_CODE_PL0));
    gdt[2] = create_gdt_entry(0, 0x000FFFFF, (GDT_DATA_PL0));
    gdt[3] = create_gdt_entry(0, 0x000FFFFF, (GDT_CODE_PL3));
    gdt[4] = create_gdt_entry(0, 0x000FFFFF, (GDT_DATA_PL3));

    // from arch/i386/gdt_asm.S
    load_gdt();
}

uint64_t create_gdt_entry(uint32_t base, uint32_t limit, uint16_t flag) {
    uint64_t entry;

    // Create the high 32 bit segment
    entry = limit & 0x000F0000;          // set limit bits 19:16
    entry |= (flag << 8) & 0x00F0FF00;   // set type, p, dpl, s, g, d/b, l and avl fields
    entry |= (base >> 16) & 0x000000FF;  // set base bits 23:16
    entry |= base & 0xFF000000;          // set base bits 31:24

    // Shift by 32 to allow for low part of segment
    entry <<= 32;

    // Create the low 32 bit segment
    entry |= base << 16;          // set base bits 15:0
    entry |= limit & 0x0000FFFF;  // set limit bits 15:0

    return entry;
}