/*
 * string/explicit_bzero.c
 * Initializes a region of memory to a byte value in a manner that is not
 * optimized away by the compiler.
 */

#include <string.h>

// TODO: Employ special compiler support to ensure this is not optimized away.
void explicit_bzero(void* dest_ptr, size_t size) {
    volatile unsigned char* dest = (volatile unsigned char*)dest_ptr;
    for (size_t i = 0; i < size; i++)
        dest[i] = 0;
}
