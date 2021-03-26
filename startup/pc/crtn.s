.section .init, "ax"
.align 16
	popl %ebp
	ret

.section .fini, "ax"
.align 16
	popl %ebp
	ret
