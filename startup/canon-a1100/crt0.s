// From chdk
.align
.section .text.boot
.type _start, #function
.global _start

ldr     SP, =0x1900

// Turn OFF SD Card power
// to support autostart
	ldr     R3, =0xC022007C
	mov     R2, #0x44
	str     R2, [R3]
	
// looks like idle cycle is required for proper shutdown
	mov     R3, #0x8000
1:
	sub	R3, R3, #1
	cmp	R3, #0
	bne	1b

// ordinary startup...

	mov     SP, #0x1900
	mov     R11, #0
	b	kernel_main
