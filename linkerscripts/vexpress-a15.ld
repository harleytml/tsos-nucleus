ENTRY(_start)
 
SECTIONS {
    /* QEMU loads the kernel in Flash here. I strongly suggest you look at the
     * memory map provided in the CoreTile TRM (see below).
     */
    
    . = 0x80010000;

	.text ALIGN(4) : 
	{
		KEEP(*(.text.boot))
		KEEP(*(.init))
    KEEP(*(.fini))
		*(.text)
		*(.text.*)
	}
 
	/* Read-only data. */
	.rodata ALIGN(16) :
	{
		*(.rodata)
		*.(.rodata.*)
	}
 
	/* Read-write data (initialized) */
	.data ALIGN(16) : 
	{
		*(.data)
		*(.data.*)
		*(vtable)
	}
 
	/* Read-write data (uninitialized) and stack */
	.bss ALIGN(16) : 
	{
		*(COMMON)
		*(.bss)
		*(.bss.*)
	}

    STACK_BASE = .;
    . += 0x10000;
    STACK_TOP = .;
}