/*
 * string/strlcpy.c
 * Copies a string and truncates it if the destination is too small.
 */

#include <string.h>

size_t strlcpy(char* restrict dest, const char* restrict src, size_t size) {
    if (!size)
        return strlen(src);
    size_t result;
    for (result = 0; result < size - 1 && src[result]; result++)
        dest[result] = src[result];
    dest[result] = '\0';
    return result + strlen(src + result);
}
