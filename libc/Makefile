DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

CFLAGS?=-O2 -g
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra -fstack-protector-all -D__is_miku_libc -Iinclude
LIBK_CFLAGS:=$(CFLAGS) -D__is_miku_libk

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
LIBK_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)

FREEOBJS=\
$(ARCH_FREEOBJS) \
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
stdlib/abort.o \
errno/errno.o \
ctype/isalnum.o \
ctype/isalpha.o \
ctype/isascii.o \
ctype/isblank.o \
ctype/iscntrl.o \
ctype/isdigit.o \
ctype/isgraph.o \
ctype/islower.o \
ctype/isprint.o \
ctype/ispunct.o \
ctype/isspace.o \
ctype/isupper.o \
ctype/isxdigit.o \
ctype/tolower.o \
ctype/toupper.o \
string/explicit_bzero.o \
string/ffsll.o \
string/ffsl.o \
string/ffs.o \
string/memccpy.o \
string/memchr.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memrchr.o \
string/memset.o \
string/stpcpy.o \
string/stpncpy.o \
string/strcasecmp.o \
string/strcat.o \
string/strchrnul.o \
string/strchr.o \
string/strcmp.o \
string/strcoll.o \
string/strcpy.o \
string/strcspn.o \
string/strerror.o \
string/strerror_r.o \
string/stresep.o \
string/strlcat.o \
string/strlcpy.o \
string/strlen.o \
string/strncasecmp.o \
string/strncat.o \
string/strncmp.o \
string/strncpy.o \
string/strnlen.o \
string/strpbrk.o \
string/strrchr.o \
string/strsep.o \
string/strspn.o \
string/strstr.o \
string/strtok.o \
string/strtok_r.o \
string/strverscmp.o \
string/strxfrm.o \
ssp/__stack_chk_fail.o \

HOSTEDOBJS=\
$(ARCH_HOSTEDOBJS) \

OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBK_OBJS=$(FREEOBJS:.o=.libk.o)

#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .S

all: $(BINARIES)

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)

.c.S:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

.c.libk.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS)

.S.libk.o:
	$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS)

clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)
