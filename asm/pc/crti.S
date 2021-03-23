.section .init
.global _init
.align 16
.type _init, @function
_init:
	push %ebp
	movl %esp, %ebp

.section .fini
.global _fini
.align 16
.type _fini, @function
_fini:
	push %ebp
	movl %esp, %ebp
