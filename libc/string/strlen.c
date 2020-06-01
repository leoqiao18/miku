/*
 * string/strlen.c
 * Returns the length of a string.
 */

#include <string.h>

size_t strlen(const char* str) {
    size_t ret = 0;
    while (str[ret])
        ret++;
    return ret;
}
