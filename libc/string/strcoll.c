/*
 * string/strcoll.c
 * Compare two strings using the current locale.
 */

#include <string.h>

int strcoll(const char* s1, const char* s2) {
    // TODO: Pay attention to locales.
    return strcmp(s1, s2);
}
