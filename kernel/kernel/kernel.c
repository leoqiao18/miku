#include <miku/kernel/tty.h>
#include <stdio.h>

void kernel_main(void) {
    int j, k;
    terminal_initialize();
    for (int i = -11; i < 1; i++) {
        printf("%i Hello, kernel World!\n", i);
    }
    printf("pointer: %p %p\n", &j, &printf);
}