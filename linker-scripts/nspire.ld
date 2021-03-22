/*By Tsuki Superior*/

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
EXTERN(_start)

SECTIONS
{
	.text :
	{
		*(.text)
	}
 
	.rodata :
	{
		*(.rodata)
	}
 
	.data :
	{
		*(.data)
	}
 
	.bss :
	{
		*(COMMON)
		*(.bss)
	}

	_kernelend = . ;
}