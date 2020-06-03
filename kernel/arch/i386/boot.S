# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
    movl $stack_top, %esp

    # Setup GDT
    call gdt_init
    subl $6, %esp
	movw gdt_size_minus_one, %cx
	movw %cx, 0(%esp)
	movl $gdt, %ecx
	movl %ecx, 2(%esp)
	lgdt 0(%esp)
	addl $6, %esp

    # Switch cs to the kernel code segment (0x08).
	push $0x08
	push $1f
	retf

1:
    # Switch ds, es, fs, gs, ss to the kernel data segment (0x10).
	movw $0x10, %cx
	movw %cx, %ds
	movw %cx, %es
	movw %cx, %fs
	movw %cx, %gs
	movw %cx, %ss

    # Call the global constructors.
    call _init

    # Transfer control to the main kernel.
    call kernel_main

    # Hang if kernel_main unexpectedly returns.
    cli
1:	hlt
    jmp 1b
.size _start, . - _start
