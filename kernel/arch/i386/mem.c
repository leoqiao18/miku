#include <miku/kernel/mem.h>
#include <miku/kernel/multiboot.h>
#include <miku/kernel/panic.h>
#include <miku/kernel/printk.h>

void mem_init(multiboot_info_t* bootinfo) {
    if (!(bootinfo->flags & MULTIBOOT_INFO_MEM_MAP)) {
        panic("The memory map flag wasn't set in the multiboot info structure!");
    }

    // getting memory map from multiboot_info
    if (bootinfo->flags & 1) {
        printk("mem_lower: %lu, mem_upper: %lu\n", bootinfo->mem_lower, bootinfo->mem_upper);
    }

    printk("mmap info:\n");
    multiboot_memory_map_t* mmap_entry = phys_to_virt((unsigned long)bootinfo->mmap_addr);
    while ((void*)mmap_entry < phys_to_virt((unsigned long)bootinfo->mmap_addr) + bootinfo->mmap_length) {
        // do something with the entry
        // size, addr, len, type
        printk("\tstart: %llX, end: %llX, len: %llu, type: %lu\n", mmap_entry->addr, mmap_entry->addr + mmap_entry->len, mmap_entry->len, mmap_entry->type);
        mmap_entry = (multiboot_memory_map_t*)((unsigned int)mmap_entry + mmap_entry->size + sizeof(mmap_entry->size));
    }
}