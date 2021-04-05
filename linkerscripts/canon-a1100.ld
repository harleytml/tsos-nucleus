/*From CHDK*/

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{

  .text :
  {
	  _start = .;
	  KEEP(*(.text.boot))
	  *(.text)
    *(.glue_7t)
    *(.glue_7)
	  . = ALIGN(4);
  }
  . = ALIGN(4);

  .data : 
  {
    *(.rodata.*)
    *(.rdata)
    . = ALIGN(4);
    *(.blob*)
	  *(.data)
	  . = ALIGN(4);
  }
  . = ALIGN(4);

  .bss : {
  	*(.bss) 
  	*(.bss.*) 
    *(COMMON)
	  . = ALIGN(16);
  }
  . = ALIGN(16);
  _kernelend = . ;
}

