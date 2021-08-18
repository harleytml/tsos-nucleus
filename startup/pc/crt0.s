# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1badb002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .text.boot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss, "aw", @nobits
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .heap, "aw", @nobits
.align 16
heap_bottom:
.skip 16384 # 16 KiB
heap_top:

# The kernel entry point.
.section .text, "ax"
.align 16
.global _start
.type _start, @function
_start:
  movl $stack_top, %esp

  # Call the global constructors.
  # The init function doesn't appear to work with clang right now
  # So i will skip
  call _init
  and $-16, %esp


  # Transfer control to the main kernel.
  call kernel_main

  # Hang if kernel_main unexpectedly returns.
  cli

_stop:	
  hlt
  jmp _stop

.size _start, . - _start
