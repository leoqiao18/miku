#include <stdio.h>

#include <miku/kernel/tty.h>

void kernel_main(void) {
    terminal_initialize();
    printf("Hello, kernel World!\n");
}
