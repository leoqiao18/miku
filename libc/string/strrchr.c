/*
 * string/strrchr.c
 * Searches a string for a specific character.
 */

#include <stdbool.h>
#include <string.h>

char* strrchr(const char* str, int uc) {
    const unsigned char* ustr = (const unsigned char*)str;
    const char* last = NULL;
    for (size_t i = 0; true; i++) {
        if (ustr[i] == (unsigned char)uc)
            last = str + i;
        if (!ustr[i])
            break;
    }
    return (char*)last;
}
