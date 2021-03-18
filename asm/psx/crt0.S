    .section .boot,"ax",@progbits
    .align 2
    .global _start
    .type _start, @function
_start:
    .set noat; .set noreorder

    la $sp, __sp
    la $gp, _gp

    li $t0, 1<<30
    mtc0 $t0,$12

    jal kernel_main
    mtc0 $0,$13

0:  j 0b
    nop
