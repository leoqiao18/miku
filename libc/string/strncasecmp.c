/*
 * string/strncasecmp.c
 * Compares a prefix of two strings ignoring case.
 */

#include <ctype.h>
#include <string.h>

int strncasecmp(const char* a, const char* b, size_t max_count) {
    for (size_t i = 0; i < max_count; i++) {
        unsigned char ac = (unsigned char)tolower((unsigned char)a[i]);
        unsigned char bc = (unsigned char)tolower((unsigned char)b[i]);
        if (ac == '\0' && bc == '\0')
            return 0;
        if (ac < bc)
            return -1;
        if (ac > bc)
            return 1;
    }
    return 0;
}
