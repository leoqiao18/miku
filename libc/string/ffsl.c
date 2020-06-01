/*
 * string/ffsl.c
 * Returns the index of the first set bit.
 */

#include <string.h>

int ffsl(long int val) {
    return __builtin_ffsl(val);
}
