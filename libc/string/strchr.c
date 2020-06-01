/*
 * string/strchr.c
 * Searches a string for a specific character.
 */

#include <string.h>

char* strchr(const char* str, int uc) {
    char* ret = strchrnul(str, uc);
    return (unsigned char)uc == ((unsigned char*)ret)[0] ? ret : NULL;
}
