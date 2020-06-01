/*
 * string/strlcat.c
 * Appends a string onto another string truncating if the string is too small.
 */

#include <string.h>

size_t strlcat(char* restrict dest, const char* restrict src, size_t size) {
    size_t dest_len = strnlen(dest, size);
    if (size <= dest_len)
        return dest_len + strlen(src);
    return dest_len + strlcpy(dest + dest_len, src, size - dest_len);
}
