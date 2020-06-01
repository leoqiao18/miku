/*
 * string/strtok_r.c
 * Extract tokens from strings.
 */

#include <string.h>

char* strtok_r(char* str, const char* delim, char** saveptr) {
    if (!str && !*saveptr)
        return NULL;
    if (!str)
        str = *saveptr;
    str += strspn(str, delim);  // Skip leading
    if (!*str)
        return *saveptr = NULL;
    size_t amount = strcspn(str, delim);
    if (str[amount])
        *saveptr = str + amount + 1;
    else
        *saveptr = NULL;
    str[amount] = '\0';
    return str;
}
