/*
 * string/strsep.c
 * Extract a token from a string.
 */

#include <string.h>

char* strsep(char** string_ptr, const char* delim) {
    char* token = *string_ptr;
    if (!token)
        return NULL;
    size_t token_length = strcspn(token, delim);
    if (token[token_length]) {
        token[token_length++] = '\0';
        *string_ptr = token + token_length;
    } else {
        *string_ptr = (char*)NULL;
    }
    return token;
}
