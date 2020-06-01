/*
 * string/ffs.c
 * Returns the index of the first set bit.
 */

#include <string.h>

int ffs(int val) {
    return __builtin_ffs(val);
}
