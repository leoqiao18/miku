/*
 * string/strerror_r.c
 * Convert error code to a string.
 */

#include <errno.h>
#include <string.h>

int strerror_r(int errnum, char* dest, size_t dest_len) {
    const char* msg = miku_strerror(errnum);
    if (!msg)
        return -1;
    if (dest_len < strlen(msg) + 1)
        return errno = ERANGE;
    strcpy(dest, msg);
    return 0;
}
