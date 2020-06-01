/*
 * wchar.h
 * Wide character support.
 */

#ifndef INCLUDE_WCHAR_H
#define INCLUDE_WCHAR_H

#include <sys/cdefs.h>

#include <__/wchar.h>

#include <stdarg.h>
#include <stddef.h>
#include <stddef.h>

typedef __wint_t wint_t;

#ifndef WCHAR_MIN
#define WCHAR_MIN __WCHAR_MIN
#endif

#ifndef WCHAR_MAX
#define WCHAR_MAX __WCHAR_MAX
#endif

#ifndef WEOF
#define WEOF __WEOF
#endif

#endif
