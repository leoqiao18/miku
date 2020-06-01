#include <libk.h>
#include <stdio.h>

void libk_stack_chk_fail() {
    printf("Stack smash!!!\n");
    while (1) ;
}