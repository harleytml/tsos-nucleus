ENTRY(_start)
 
SECTIONS {
    /* QEMU loads the kernel in Flash here. I strongly suggest you look at the
     * memory map provided in the CoreTile TRM (see below).
     */
    
  . = 0x80010000;

	.text : 
	{
		KEEP(*(.text.boot))
		KEEP(*(.init))
    KEEP(*(.fini))
		*(.text)
		*(.text.*)
	}
 
	/* Read-only data. */
	.rodata :
	{
		*(.rodata)
		*.(.rodata.*)
	}
 
	/* Read-write data (initialized) */
	.data : 
	{
		*(.data)
		*(.data.*)
		*(vtable)
	}
 
	/* Read-write data (uninitialized) and stack */
	.bss : 
	{
		*(COMMON)
		*(.bss)
		*(.bss.*)
	}
}