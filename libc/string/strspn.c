/*

 * string/strspn.c
 * Search a string for a set of characters.
 */

#include <stdbool.h>
#include <string.h>

size_t strspn(const char* str, const char* accept) {
    size_t accept_length = 0;
    while (accept[accept_length])
        accept_length++;
    for (size_t result = 0; true; result++) {
        char c = str[result];
        if (!c)
            return result;
        bool matches = false;
        for (size_t i = 0; i < accept_length; i++) {
            if (str[result] != accept[i])
                continue;
            matches = true;
            break;
        }
        if (!matches)
            return result;
    }
}
