#ifndef __INCLUDE_STDIO_H
#define __INCLUDE_STDIO_H

#include <stdarg.h>
#include <sys/cdefs.h>

#define EOF (-1)

__attribute__((format(printf, 1, 2))) int printf(const char* __restrict, ...);
__attribute__((format(printf, 1, 0))) int vprintf(const char* format, va_list list);
int putchar(int);
int puts(const char*);

#endif  //__INCLUDE_STDIO_H
