/*
 * string/strchrnul.c
 * Searches a string for a specific character.
 */

#include <stdbool.h>
#include <string.h>

char* strchrnul(const char* str, int uc) {
    const unsigned char* ustr = (const unsigned char*)str;
    for (size_t i = 0; true; i++)
        if (ustr[i] == (unsigned char)uc || !ustr[i])
            return (char*)str + i;
}
