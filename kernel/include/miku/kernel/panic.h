#ifndef __INCLUDE_MIKU_KERNEL_PANIC_H
#define __INCLUDE_MIKU_KERNEL_PANIC_H

#include <stdarg.h>

/* Defined in arch */
__attribute__((noreturn)) void halt_kernel();

__attribute__((noreturn)) void panic(const char *error);
__attribute__((noreturn, format(printf, 1, 2))) void panicf(const char *format, ...);

#endif  //__INCLUDE_MIKU_KERNEL_PANIC_H