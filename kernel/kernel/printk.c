#include <miku/kernel/printk.h>
#include <stdarg.h>
#include <stdio.h>

__attribute__((format(printf, 1, 2))) void printk(const char *format, ...) {
    va_list list;
    va_start(list, format);
    vprintf(format, list);
    va_end(list);
}