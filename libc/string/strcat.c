/*
 * string/strcat.c
 * Appends a string onto another string.
 */

#include <string.h>

char* strcat(char* dest, const char* src) {
    strcpy(dest + strlen(dest), src);
    return dest;
}
