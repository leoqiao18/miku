/*
 * wchar.h
 * Wide character support.
 */

#ifndef INCLUDE_WCHAR_H
#define INCLUDE_WCHAR_H

#include <stdarg.h>
#include <stddef.h>
#include <sys/cdefs.h>

typedef __WCHAR_TYPE__ __wchar_t;
#define __WCHAR_MIN __WCHAR_MIN__
#define __WCHAR_MAX __WCHAR_MAX__

typedef __WINT_TYPE__ __wint_t;
#define __WINT_MIN __WINT_MIN__
#define __WINT_MAX __WINT_MAX__

#define __WEOF __WINT_MAX

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
