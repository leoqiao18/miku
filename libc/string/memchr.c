/*
 * string/memchr.c
 * Scans memory for a character.
 */

#include <string.h>

void* memchr(const void* s, int c, size_t size) {
    const unsigned char* buf = (const unsigned char*)s;
    for (size_t i = 0; i < size; i++)
        if (buf[i] == (unsigned char)c)
            return (void*)(buf + i);
    return NULL;
}
