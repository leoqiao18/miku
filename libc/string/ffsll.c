/*
 * string/ffsll.c
 * Returns the index of the first set bit.
 */

#include <string.h>

int ffsll(long long int val) {
    return __builtin_ffsll(val);
}
