/*
 * string/memmove.c
 * Copy memory between potentionally overlapping regions.
 */

#include <stdint.h>
#include <string.h>

void* memmove(void* dest_ptr, const void* src_ptr, size_t n) {
    unsigned char* dest = (unsigned char*)dest_ptr;
    const unsigned char* src = (const unsigned char*)src_ptr;
    if ((uintptr_t)dest < (uintptr_t)src) {
        for (size_t i = 0; i < n; i++)
            dest[i] = src[i];
    } else {
        for (size_t i = 0; i < n; i++)
            dest[n - (i + 1)] = src[n - (i + 1)];
    }
    return dest_ptr;
}
