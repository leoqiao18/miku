#include <miku/arch/i386/kernel_layout.h>
#include <miku/kernel/multiboot.h>
#include <miku/kernel/tty.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*)VGA_VIRT_ADDR;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_init(multiboot_info_t* bootinfo) {
    (void)bootinfo;

    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = VGA_MEMORY;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_set_color(uint8_t color) {
    terminal_color = color;
}

void terminal_put_entry_at(unsigned char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal_shift_up(size_t n) {
    if (n > VGA_HEIGHT) {
        n = VGA_HEIGHT;
    }

    memmove(terminal_buffer, terminal_buffer + n * VGA_WIDTH, sizeof(terminal_buffer[0]) * (VGA_HEIGHT - n) * VGA_WIDTH);
    for (size_t y = VGA_HEIGHT - n; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_prepare_new_entry() {
    if (terminal_column >= VGA_WIDTH) {
        terminal_column = 0;
        terminal_row++;
    }
    if (terminal_row >= VGA_HEIGHT) {
        terminal_shift_up(terminal_row - VGA_HEIGHT + 1);
        terminal_row = VGA_HEIGHT - 1;
    }
}

void terminal_put_char(char c) {
    unsigned char uc = c;
    switch (uc) {
        case '\n':
            terminal_column = 0;
            terminal_row++;
            break;
        case '\t':
            terminal_column = terminal_column + (8 - (terminal_column % 8));
            break;
        default:
            terminal_prepare_new_entry();
            terminal_put_entry_at(uc, terminal_color, terminal_column, terminal_row);
            terminal_column++;
    }
}

void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminal_put_char(data[i]);
}

void terminal_write_string(const char* data) {
    terminal_write(data, strlen(data));
}

void terminal_clear() {
    terminal_shift_up(VGA_HEIGHT);
}