.section .text
.global load_gdt
.type load_gdt, @function
load_gdt:
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
    ret
.size load_gdt, . - load_gdt