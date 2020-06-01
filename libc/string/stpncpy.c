/*
 * string/stpncpy.c
 * Copies a string into a fixed size buffer and returns last byte.
 */

#include <string.h>

char* stpncpy(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    char* ret = dest + i;
    for (; i < n; i++)
        dest[i] = '\0';
    return ret;
}
