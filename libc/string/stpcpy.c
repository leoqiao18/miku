/*
 * string/stpcpy.c
 * Copy a string returning a pointer to its end.
 */

#include <string.h>

char* stpcpy(char* dest, const char* src) {
    size_t index;
    for (index = 0; src[index]; index++)
        dest[index] = src[index];
    dest[index] = '\0';
    return dest + index;
}
