#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

// static void __reverse_string(char *str, size_t n) {
//     /* skip null */
//     if (str == 0) {
//         return;
//     }

//     /* skip empty string */
//     if (*str == 0) {
//         return;
//     }

//     /* get range */
//     char *start = str;
//     char *end = start + n - 1; /* -1 for \0 */
//     char temp;

//     /* reverse */
//     while (end > start) {
//         /* swap */
//         temp = *start;
//         *start = *end;
//         *end = temp;

//         /* move */
//         ++start;
//         --end;
//     }
// }

// static char *__itoa(unsigned int num, char *str, int base, bool should_negative) {
//     int i = 0;
//     bool isNegative = false;
//     int signed_num = (int)num;

//     /* Handle 0 explicitely, otherwise empty string is printed for 0 */
//     if (num == 0) {
//         str[i++] = '0';
//         str[i] = '\0';
//         return str;
//     }

//     // In standard itoa(), negative numbers are handled only with
//     // base 10. Otherwise numbers are considered unsigned.
//     if (signed_num < 0 && base == 10 && should_negative) {
//         isNegative = true;
//         signed_num = -signed_num;
//         num = (unsigned int)signed_num;
//     }

//     // Process individual digits
//     while (num != 0) {
//         int rem = num % base;
//         str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
//         num = num / base;
//     }

//     // If number is negative, append '-'
//     if (isNegative) str[i++] = '-';

//     str[i] = '\0';  // Append string terminator

//     // Reverse the string
//     __reverse_string(str, i);

//     return str;
// }

// static bool print(const char *data, size_t length) {
//     const unsigned char *bytes = (const unsigned char *)data;
//     for (size_t i = 0; i < length; i++)
//         if (putchar(bytes[i]) == EOF) return false;
//     return true;
// }

// int printf(const char *restrict format, ...) {
//     va_list parameters;
//     va_start(parameters, format);

//     int written = 0;
//     char buf[100];

//     while (*format != '\0') {
//         size_t maxrem = INT_MAX - written;

//         if (format[0] != '%' || format[1] == '%') {
//             if (format[0] == '%') format++;
//             size_t amount = 1;
//             while (format[amount] && format[amount] != '%') amount++;
//             if (maxrem < amount) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(format, amount)) return -1;
//             format += amount;
//             written += amount;
//             continue;
//         }

//         const char *format_begun_at = format++;

//         /*
//          * TODO:
//          * 1. d/i
//          * 2. u
//          * 3. o
//          * 4. x
//          * 5. X
//          * 6. f
//          * 7. p
//          */
//         if (*format == 'c') {
//             format++;
//             char c = (char)va_arg(parameters, int /* char promotes to int */);
//             if (!maxrem) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(&c, sizeof(c))) return -1;
//             written++;
//         } else if (*format == 's') {
//             format++;
//             const char *str = va_arg(parameters, const char *);
//             size_t len = strlen(str);
//             if (maxrem < len) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(str, len)) return -1;
//             written += len;
//         } else if (*format == 'd' || *format == 'i') {
//             format++;
//             int n = va_arg(parameters, int);
//             __itoa(n, buf, 10, true);
//             size_t len = strlen(buf);
//             if (maxrem < len) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(buf, len)) return -1;
//             written += len;
//         } else if (*format == 'u') {
//             format++;
//             unsigned int n = va_arg(parameters, unsigned int);
//             __itoa(n, buf, 10, false);
//             size_t len = strlen(buf);
//             if (maxrem < len) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(buf, len)) return -1;
//             written += len;
//         } else {
//             format = format_begun_at;
//             size_t len = strlen(format);
//             if (maxrem < len) {
//                 // TODO: Set errno to EOVERFLOW.
//                 return -1;
//             }
//             if (!print(format, len)) return -1;
//             written += len;
//             format += len;
//         }
//     }

//     va_end(parameters);
//     return written;
// }

// Example implementation
char* __int_str(intmax_t i, char b[], int base, bool plusSignIfNeeded, bool spaceSignIfNeeded,
                int paddingNo, bool justify, bool zeroPad) {
    char digit[32] = {0};
    memset(digit, 0, 32);
    strcpy(digit, "0123456789");

    if (base == 16) {
        strcat(digit, "ABCDEF");
    } else if (base == 17) {
        strcat(digit, "abcdef");
        base = 16;
    }

    char* p = b;
    if (i < 0) {
        *p++ = '-';
        i *= -1;
    } else if (plusSignIfNeeded) {
        *p++ = '+';
    } else if (!plusSignIfNeeded && spaceSignIfNeeded) {
        *p++ = ' ';
    }

    intmax_t shifter = i;
    do {
        ++p;
        shifter = shifter / base;
    } while (shifter);

    *p = '\0';
    do {
        *--p = digit[i % base];
        i = i / base;
    } while (i);

    int padding = paddingNo - (int)strlen(b);
    if (padding < 0) padding = 0;

    if (justify) {
        while (padding--) {
            if (zeroPad) {
                b[strlen(b)] = '0';
            } else {
                b[strlen(b)] = ' ';
            }
        }

    } else {
        char a[256] = {0};
        while (padding--) {
            if (zeroPad) {
                a[strlen(a)] = '0';
            } else {
                a[strlen(a)] = ' ';
            }
        }
        strcat(a, b);
        strcpy(b, a);
    }

    return b;
}

void displayCharacter(char c, int* a) {
    putchar(c);
    *a += 1;
}

void displayString(char* c, int* a) {
    for (int i = 0; c[i]; ++i) {
        displayCharacter(c[i], a);
    }
}

int vprintf(const char* format, va_list list) {
    int chars = 0;
    char intStrBuffer[256] = {0};

    for (int i = 0; format[i]; ++i) {
        char specifier = '\0';
        char length = '\0';

        int lengthSpec = 0;
        int precSpec = 0;
        bool leftJustify = false;
        bool zeroPad = false;
        bool spaceNoSign = false;
        bool altForm = false;
        bool plusSign = false;
        bool emode = false;
        int expo = 0;

        if (format[i] == '%') {
            ++i;

            bool extBreak = false;
            while (1) {
                switch (format[i]) {
                    case '-':
                        leftJustify = true;
                        ++i;
                        break;

                    case '+':
                        plusSign = true;
                        ++i;
                        break;

                    case '#':
                        altForm = true;
                        ++i;
                        break;

                    case ' ':
                        spaceNoSign = true;
                        ++i;
                        break;

                    case '0':
                        zeroPad = true;
                        ++i;
                        break;

                    default:
                        extBreak = true;
                        break;
                }

                if (extBreak) break;
            }

            while (isdigit(format[i])) {
                lengthSpec *= 10;
                lengthSpec += format[i] - 48;
                ++i;
            }

            if (format[i] == '*') {
                lengthSpec = va_arg(list, int);
                ++i;
            }

            if (format[i] == '.') {
                ++i;
                while (isdigit(format[i])) {
                    precSpec *= 10;
                    precSpec += format[i] - 48;
                    ++i;
                }

                if (format[i] == '*') {
                    precSpec = va_arg(list, int);
                    ++i;
                }
            } else {
                precSpec = 6;
            }

            if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j' ||
                format[i] == 'z' || format[i] == 't' || format[i] == 'L') {
                length = format[i];
                ++i;
                if (format[i] == 'h') {
                    length = 'H';
                } else if (format[i] == 'l') {
                    length = 'q';
                }
            }
            specifier = format[i];

            memset(intStrBuffer, 0, 256);

            int base = 10;
            if (specifier == 'o') {
                base = 8;
                specifier = 'u';
                if (altForm) {
                    displayString("0", &chars);
                }
            }
            if (specifier == 'p') {
                base = 16;
                length = 'z';
                specifier = 'u';
            }
            switch (specifier) {
                case 'X':
                    base = 16;
                    __attribute__((fallthrough));
                case 'x':
                    base = base == 10 ? 17 : base;
                    if (altForm) {
                        displayString("0x", &chars);
                    }
                    __attribute__((fallthrough));
                case 'u': {
                    switch (length) {
                        case 0: {
                            unsigned int integer = va_arg(list, unsigned int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'H': {
                            unsigned char integer = (unsigned char)va_arg(list, unsigned int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'h': {
                            unsigned short int integer = va_arg(list, unsigned int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'l': {
                            unsigned long integer = va_arg(list, unsigned long);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'q': {
                            unsigned long long integer = va_arg(list, unsigned long long);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'j': {
                            uintmax_t integer = va_arg(list, uintmax_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'z': {
                            size_t integer = va_arg(list, size_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 't': {
                            ptrdiff_t integer = va_arg(list, ptrdiff_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }

                case 'd':
                case 'i': {
                    switch (length) {
                        case 0: {
                            int integer = va_arg(list, int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'H': {
                            signed char integer = (signed char)va_arg(list, int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'h': {
                            short int integer = va_arg(list, int);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'l': {
                            long integer = va_arg(list, long);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'q': {
                            long long integer = va_arg(list, long long);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'j': {
                            intmax_t integer = va_arg(list, intmax_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 'z': {
                            size_t integer = va_arg(list, size_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        case 't': {
                            ptrdiff_t integer = va_arg(list, ptrdiff_t);
                            __int_str(integer, intStrBuffer, base, plusSign, spaceNoSign, lengthSpec, leftJustify, zeroPad);
                            displayString(intStrBuffer, &chars);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }

                case 'c': {
                    if (length == 'l') {
                        displayCharacter(va_arg(list, wint_t), &chars);
                    } else {
                        displayCharacter(va_arg(list, int), &chars);
                    }

                    break;
                }

                case 's': {
                    displayString(va_arg(list, char*), &chars);
                    break;
                }

                case 'n': {
                    switch (length) {
                        case 'H':
                            *(va_arg(list, signed char*)) = chars;
                            break;
                        case 'h':
                            *(va_arg(list, short int*)) = chars;
                            break;

                        case 0: {
                            int* a = va_arg(list, int*);
                            *a = chars;
                            break;
                        }

                        case 'l':
                            *(va_arg(list, long*)) = chars;
                            break;
                        case 'q':
                            *(va_arg(list, long long*)) = chars;
                            break;
                        case 'j':
                            *(va_arg(list, intmax_t*)) = chars;
                            break;
                        case 'z':
                            *(va_arg(list, size_t*)) = chars;
                            break;
                        case 't':
                            *(va_arg(list, ptrdiff_t*)) = chars;
                            break;
                        default:
                            break;
                    }
                    break;
                }

                case 'e':
                case 'E':
                    emode = true;
                    __attribute__((fallthrough));
                case 'f':
                case 'F':
                case 'g':
                case 'G': {
                    double floating = va_arg(list, double);

                    while (emode && floating >= 10) {
                        floating /= 10;
                        ++expo;
                    }

                    int form = lengthSpec - precSpec - expo - (precSpec || altForm ? 1 : 0);
                    if (emode) {
                        form -= 4;  // 'e+00'
                    }
                    if (form < 0) {
                        form = 0;
                    }

                    __int_str(floating, intStrBuffer, base, plusSign, spaceNoSign, form,
                              leftJustify, zeroPad);

                    displayString(intStrBuffer, &chars);

                    floating -= (int)floating;

                    for (int i = 0; i < precSpec; ++i) {
                        floating *= 10;
                    }
                    intmax_t decPlaces = (intmax_t)(floating + 0.5);

                    if (precSpec) {
                        displayCharacter('.', &chars);
                        __int_str(decPlaces, intStrBuffer, 10, false, false, 0, false, false);
                        intStrBuffer[precSpec] = 0;
                        displayString(intStrBuffer, &chars);
                    } else if (altForm) {
                        displayCharacter('.', &chars);
                    }

                    break;
                }

                case 'a':
                case 'A':
                    //ACK! Hexadecimal floating points...
                    break;

                default:
                    break;
            }

            if (specifier == 'e') {
                displayString("e+", &chars);
            } else if (specifier == 'E') {
                displayString("E+", &chars);
            }

            if (specifier == 'e' || specifier == 'E') {
                __int_str(expo, intStrBuffer, 10, false, false, 2, false, true);
                displayString(intStrBuffer, &chars);
            }

        } else {
            displayCharacter(format[i], &chars);
        }
    }

    return chars;
}

__attribute__((format(printf, 1, 2))) int printf(const char* format, ...) {
    va_list list;
    va_start(list, format);
    int i = vprintf(format, list);
    va_end(list);
    return i;
}