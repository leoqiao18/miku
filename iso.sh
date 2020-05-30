#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/miku.kernel isodir/boot/miku.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "miku" {
	multiboot /boot/miku.kernel
}
EOF
grub-mkrescue -o miku.iso isodir
