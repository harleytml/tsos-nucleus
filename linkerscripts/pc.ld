OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i686)
ENTRY(_start)
 
SECTIONS
{
	/* 
	 * Begin putting sections at 1 MiB, a conventional place for kernels to be
	 *  loaded at by the bootloader.
	 */

	. = 1M;

	.text ALIGN(4K) : 
	{
    KEEP(*(.text.boot))
		*(.text .text.*)
		*(.init)
		*(.fini)
	}
 
	/* 
   * Read-only data.
   */
   
	.rodata  ALIGN(4K) :
	{
		*(.rodata .rodata.*)
	}
 
	/* 
   * Read-write data (initialized) 
   */

	.data ALIGN(4K) : 
	{
		*(.data .data.*)
		*(vtable)
	}
 
	/* 
   * Read-write data (uninitialized) and stack
   */

	.bss ALIGN(4K) : 
	{
		*(.bss .bss.*) 
		*(COMMON)
    LONG(0)
	}

	.heap ALIGN(16):
	{
		_LINKER_kernel_heap = .;
		(.heap)
		(.heap.*)
	}

  /DISCARD/ :
  { 
      *(.comment) 
      *(.gnu*) 
      *(.note*) 
      *(.eh_frame*)
  }
}
