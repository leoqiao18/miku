#include <miku/kernel/panic.h>
#include <stdarg.h>
#include <stdio.h>

__attribute__((noreturn)) void panic(const char *error) {
    printf(error);
    printf("\n");
    printf("KERNEL PANIC!!!\n");
    halt_kernel();
}

__attribute__((noreturn, format(printf, 1, 2))) void panicf(const char *format, ...) {
    va_list list;
    va_start(list, format);
    vprintf(format, list);
    va_end(list);
    printf("\n");
    printf("KERNEL PANIC!!!\n");
    halt_kernel();
}