/*
 * string/strncmp.c
 * Compares a prefix of two strings.
 */

#include <string.h>

int strncmp(const char* a, const char* b, size_t max_count) {
    for (size_t i = 0; i < max_count; i++) {
        unsigned char ac = (unsigned char)a[i];
        unsigned char bc = (unsigned char)b[i];
        if (ac == '\0' && bc == '\0')
            return 0;
        if (ac < bc)
            return -1;
        if (ac > bc)
            return 1;
    }
    return 0;
}
