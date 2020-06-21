#ifndef __INCLUDE_MIKU_KERNEL_PRINTK_H
#define __INCLUDE_MIKU_KERNEL_PRINTK_H

#include <stdarg.h>

__attribute__((format(printf, 1, 2))) void printk(const char *format, ...);

#endif  //__INCLUDE_MIKU_KERNEL_PRINTK_H