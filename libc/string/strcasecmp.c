/*
 * string/strcasecmp.c
 * Compares two strings ignoring case.
 */

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int strcasecmp(const char* a, const char* b) {
    for (size_t i = 0; true; i++) {
        unsigned char ac = (unsigned char)tolower((unsigned char)a[i]);
        unsigned char bc = (unsigned char)tolower((unsigned char)b[i]);
        if (ac == '\0' && bc == '\0')
            return 0;
        if (ac < bc)
            return -1;
        if (ac > bc)
            return 1;
    }
}
