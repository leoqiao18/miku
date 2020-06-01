/*
 * string/strcpy.c
 * Copies a string and returns dest.
 */

#include <string.h>

char* strcpy(char* dest, const char* src) {
    size_t index;
    for (index = 0; src[index]; index++)
        dest[index] = src[index];
    dest[index] = '\0';
    return dest;
}
