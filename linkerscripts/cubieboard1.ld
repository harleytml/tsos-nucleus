/*By Tsuki Superior*/

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{
  . = 0x40007000;
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

  .heap :
  {
    LINKER_kernel_heap =  ADDR(.heap);
    *(.heap)
    *(.heap.*)
    LONG(0)
  }

  /DISCARD/ :
  { 
    *(.comment) 
    *(.gnu*) 
    *(.note*) 
    *(.eh_frame*)
    *(.ARM.exidx .ARM.exidx.*);
  }
  
  _kernelend = . ;
}
