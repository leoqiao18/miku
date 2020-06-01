#ifndef __INCLUDE_STRING_H
#define __INCLUDE_STRING_H

#include <stddef.h>
#include <sys/cdefs.h>

void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
char* strcat(char* __restrict, const char* __restrict);
char* strchr(const char*, int);
int strcmp(const char*, const char*);
int strcoll(const char*, const char*);
char* strcpy(char* __restrict, const char* __restrict);
size_t strcspn(const char*, const char*);

char *strerror(int);

size_t strlen(const char*);
char* strncat(char* __restrict, const char* __restrict, size_t);
int strncmp(const char*, const char*, size_t);
char* strncpy(char* __restrict, const char* __restrict, size_t);
char* strpbrk(const char*, const char*);
char* strrchr(const char*, int);
size_t strspn(const char*, const char*);
char* strstr(const char*, const char*);
char* strtok(char* __restrict, const char* __restrict);
size_t strxfrm(char* __restrict, const char* __restrict, size_t);

int strcasecmp(const char* a, const char* b);
int strncasecmp(const char* a, const char* b, size_t n);

void* memccpy(void* __restrict, const void* __restrict, int, size_t);

char* strdup(const char*);

int ffs(int);
int strerror_r(int, char*, size_t);
char* strtok_r(char* __restrict, const char* __restrict, char** __restrict);

char* stpcpy(char* __restrict, const char* __restrict);
char* stpncpy(char* __restrict, const char* __restrict, size_t);
char* strndup(const char*, size_t);
size_t strnlen(const char*, size_t);

void explicit_bzero(void*, size_t);
int ffsl(long int);
void* memrchr(const void*, int, size_t);
/* TODO: strcasecmp_l */
char* strchrnul(const char* str, int c);
char* stresep(char**, const char*, int);
size_t strlcat(char* __restrict, const char* __restrict, size_t);
size_t strlcpy(char* __restrict, const char* __restrict, size_t);
/* TODO: strncasecmp_l */
char* strsep(char**, const char*);
int strverscmp(const char*, const char*);

// miku extensions
int ffsll(long long int);
const char* miku_strerror(int errnum);
const char* miku_strsignal(int signum);

#endif //__INCLUDE_STRING_H
