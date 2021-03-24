/*By Tsuki Superior*/

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
EXTERN(_start)

SECTIONS
{
	.text ALIGN(4) : 
	{
		KEEP(*(.init))
    KEEP(*(.fini))
		*(.text)
		*(.text.*)
		*(.ctors)
		*(.dtors)
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
	_kernelend = . ;
}