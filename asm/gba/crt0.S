@********************************************************************
@*   crt0.S v1.28 by Jeff Frohwein                                  *
@********************************************************************

@ v1.0 - Original release
@ v1.1 - Added proper .data section support
@ v1.2 - Added support for c++, overlays, interrupts, and
@        far calls (__FarFunction & __FarProcedure).
@      - Some ideas from Jason Wilkins & Mike Heckenbach.
@ v1.21- Killed the dumb test bug left in the code.
@ v1.22- Killed dumb bug "numero dos" in multiple interrupts routine. Thanks Mike H. :)
@ v1.23- Now correctly handles zero length .bss section.
@ v1.24- Loop back to start_vector now works if main {} exits.
@ v1.25- __FarProcedure now works. It was missing a .thumb_func directive.
@ v1.26- Added missing Serial Interrupt processing to __MultipleInterrupts section.
@        Added __FastInterrupt option for minimal interrupt processing.
@        Optimized __MultipleInterrupts section to save 4 bytes of stack space.
@        Added __ISRinIWRAM option that puts interrupt processing in IWRAM by default.
@        Options passed to main() or AgbMain() are now set to 0. (Thanks to DarkFader)
@ v1.27- Even though it might not cause any problems for anyone "as is",
@        changed .SECTION .iwram to .SECTION .iwram,"ax",%progbits
@        just to be safe. That is the more correct description/definition.
@        Added warning below about small default interrupt stack.
@ v1.28- Added force alignment (align 4) to CopyMem & ClearMem to
@        prevent infinite loops in cases where LD (buggy?) fails
@        to align(4). (Thanks to Mark Price & others.)
@
@ This file is released into the public domain for commercial
@ or non-commercial usage with no restrictions placed upon it.

.text

.global     _start
_start:
        .align
        .code 32
    @ Start Vector

        b       rom_header_end

    @ Nintendo Logo Character Data (8000004h)
        .fill   156,1,0

    @ Game Title (80000A0h)
        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        .byte   0x00,0x00,0x00,0x00

    @ Game Code (80000ACh)
        .ascii   "TSOS"

    @ Maker Code (80000B0h)
        .byte   0x30,0x31

    @ Fixed Value (80000B2h)
        .byte   0x96

    @ Main Unit Code (80000B3h)
        .byte   0x00

    @ Device Type (80000B4h)
        .byte   0x00

    @ Unused Data (7Byte) (80000B5h)
        .byte   0x00,0x00,0x00,0x00,0x00,0x00,0x00

    @ Software Version No (80000BCh)
        .byte   0x00

    @ Complement Check (80000BDh)
        .byte   0xf0

    @ Checksum (80000BEh)
        .byte   0x00,0x00

    .align
    .code 32

rom_header_end:
        b       start_vector        @ This branch must be here for proper
                                    @ positioning of the following header.
                                    @ DO NOT REMOVE IT.

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ The following reserved bytes are used if the code is compiled for      @
@ multiboot mode. It does not hurt anything to leave this header in
@ even if the code is not compiled for multiboot. The GBA BIOS will
@ auto-patch the first two bytes with 0x03 and 0x01, respectively,
@ before running any code if it is executed as multiboot.
@

@ The following two bytes are included even for non-multiboot supporting
@ builds to guarantee that any generic library code that depends on them
@ will still be functional.

.global     __boot_method, __slave_number

__boot_method:
        .byte   0       @ boot method (0=ROM boot, 3=Multiplay boot)
__slave_number:
        .byte   0       @ slave # (1=slave#1, 2=slave#2, 3=slave#3)

@                                                                        @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


@@@@@@@@@@@@@@@@@@@@@@
@        Reset       @
@@@@@@@@@@@@@@@@@@@@@@

    .global     start_vector
    .align
    .code 32
start_vector:
        mov     r0, #0x12               @ Switch to IRQ Mode
        msr     cpsr, r0
        ldr     sp,=__sp_irq            @ Set SP_irq
        mov     r0, #0x1f               @ Switch to System Mode
        msr     cpsr, r0
        ldr     sp,=__sp_usr            @ Set SP_usr

@ Enter Thumb mode
        adr    r0,1f + 1                @ add r0,pc,#1 also works here
                                        @  for those that want to conserve labels.
        bx     r0

        .code 16
1:
b 1b