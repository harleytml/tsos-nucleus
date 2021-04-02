
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
  ROM    : ORIGIN = 0x08000000, LENGTH = 32M
  EWRAM  : ORIGIN = 0x02000000, LENGTH = 256K
  IWRAM  : ORIGIN = 0x03000000, LENGTH = 32K
}

__text_start  = ORIGIN(ROM);
__app_start   = __text_start + 0xe0;
__eheap_end   = ORIGIN(EWRAM) + LENGTH(EWRAM);
__iwram_start = ORIGIN(IWRAM);
__iwram_top   = ORIGIN(IWRAM) + LENGTH(IWRAM);
__sp_irq      = __iwram_top - 0x060;
__sp_usr      = __sp_irq - 0x0a0;
__irq_flags   = 0x03007ff8;

SECTIONS
{
  VMA = __text_start ;
  . += VMA;

  /* static data stored in cart ROM */
  .header ALIGN(4) : AT(ADDR(.header) - VMA)
  {
    KEEP(*(.header.header));
  } > ROM

  .text ALIGN(4) : AT(ADDR(.text) - VMA)
  { 
    KEEP(*(.text.boot));
    KEEP(*(.text.reset_handler));
    KEEP(*(.text.isr));
    *(.text .text.*); 
  } > ROM

  .rodata ALIGN(4) : AT(ADDR(.rodata) - VMA)
  { 
    *(.rodata .rodata.*);
  } > ROM

  /* dynamic data placed in IWRAM */
  .data ALIGN(4) : AT(ADDR(.data) - VMA)
  { 

    *(.data .data.*);

  } > IWRAM AT > ROM

  .bss ALIGN(4) : AT(ADDR(.bss) - VMA)
  {

    *(.bss .bss.*); 

  } > IWRAM

  . = _kernelend

  /* discard arm symbols */
  /DISCARD/ :
  {
    *(.ARM.exidx .ARM.exidx.*);
    *(.comment) 
    *(.gnu*) 
    *(.note*) 
    *(.eh_frame*)
  }
}