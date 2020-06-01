/*
 * string/strstr.c
 * Locate a substring.
 */

#include <stdbool.h>
#include <string.h>

// TODO: This simple and hacky implementation runs in O(N^2) even though this
// problem can be solved in O(N).
char* strstr(const char* haystack, const char* needle) {
    if (!needle[0])
        return (char*)haystack;
    for (size_t i = 0; haystack[i]; i++) {
        bool diff = false;
        for (size_t j = 0; needle[j]; j++) {
            if (haystack[i + j] != needle[j]) {
                diff = true;
                break;
            }
        }
        if (diff)
            continue;
        return (char*)haystack + i;
    }
    return NULL;
}
