/*
 * string/strpbrk.c
 * Search a string for any of a set of characters.
 */

#include <string.h>

char* strpbrk(const char* str, const char* accept) {
    size_t reject_length = strcspn(str, accept);
    if (!str[reject_length])
        return NULL;
    return (char*)str + reject_length;
}
