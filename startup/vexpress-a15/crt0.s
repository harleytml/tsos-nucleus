.global _start

// Reserve a stack for the initial thread.
.section .bss, "aw", %nobits
stack_bottom:
.skip 16384 // 16 KiB
stack_top:

.section .text.boot
_start:
    ldr sp, =stack_top
    bl kernel_main
1:
    b 1b
