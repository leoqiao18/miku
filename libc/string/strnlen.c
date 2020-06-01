/*
 * string/strnlen.c
 * Returns the length of a fixed length string.
 */

#include <string.h>

size_t strnlen(const char* str, size_t maxlen) {
    size_t ret = 0;
    while (ret < maxlen && str[ret])
        ret++;
    return ret;
}
