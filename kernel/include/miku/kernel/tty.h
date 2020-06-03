#ifndef __INCLUDE_MIKU_KERNEL_TTY_H
#define __INCLUDE_MIKU_KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_put_char(char c);
void terminal_write(const char* data, size_t size);
void terminal_write_string(const char* data);

#endif //__INCLUDE_MIKU_KERNEL_TTY_H
