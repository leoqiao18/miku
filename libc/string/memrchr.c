/*
 * string/memrchr.c
 * Scans memory in reverse directory for a character.
 */

#include <stdint.h>
#include <string.h>

void* memrchr(const void* ptr, int c, size_t n) {
    const unsigned char* buf = (const unsigned char*)ptr;
    for (size_t i = n; i != 0; i--)
        if (buf[i - 1] == (unsigned char)c)
            return (void*)(buf + i - 1);
    return NULL;
}
