#ifndef __INCLUDE_MIKU_KERNEL_TTY_H
#define __INCLUDE_MIKU_KERNEL_TTY_H

#include <miku/kernel/multiboot.h>
#include <stddef.h>

void terminal_init(multiboot_info_t* bootinfo);
void terminal_put_char(char c);
void terminal_write(const char* data, size_t size);
void terminal_write_string(const char* data);
void terminal_clear();

#endif  //__INCLUDE_MIKU_KERNEL_TTY_H
