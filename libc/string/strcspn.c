/*
 * string/strcspn.c
 * Search a string for a set of characters.
 */

#include <stdbool.h>
#include <string.h>

size_t strcspn(const char* str, const char* reject) {
    size_t reject_length = 0;
    while (reject[reject_length])
        reject_length++;
    for (size_t result = 0; true; result++) {
        char c = str[result];
        if (!c)
            return result;
        bool matches = false;
        for (size_t i = 0; i < reject_length; i++) {
            if (str[result] != reject[i])
                continue;
            matches = true;
            break;
        }
        if (matches)
            return result;
    }
}
