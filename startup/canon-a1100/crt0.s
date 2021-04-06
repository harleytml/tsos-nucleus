// From chdk
.align
.section .text.boot
.type _start, #function
.global _start

ldr     sp, =0x1900

// Turn OFF SD Card power
// to support autostart
ldr     r3, =0xc022007c
mov     r2, #0x44
str     r2, [r3]
	
// looks like idle cycle is required for proper shutdown
	mov     r3, #0x8000
1:
	sub	r3, r3, #1
	cmp	r3, #0
	bne	1b

// ordinary startup...

	mov     sp, #0x1900
	mov     r11, #0
	b	kernel_main
