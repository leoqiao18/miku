/*
 * string/strtok.c
 * Extract tokens from strings.
 */

#include <string.h>

char* strtok(char* str, const char* delim) {
    static char* lasttokensaveptr = NULL;
    return strtok_r(str, delim, &lasttokensaveptr);
}
