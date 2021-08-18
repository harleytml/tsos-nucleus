ENTRY(_start)
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH(aarch64)

SECTIONS
{
    /* Starts at LOADER_ADDR. */
    . = 0x80000;
    .text ALIGN(4K) :
    {
        KEEP(*(.text.boot))
        *(.text .text.*)
    }
 
    .rodata ALIGN(4K) :
    {
        *(.rodata .rodata.*)
    }
 
    .data ALIGN(4K)  :
    {
        *(.data .data.*)
    }
 
    __bss_start = .;
    .bss ALIGN(4K) :
    {
        bss = .;
        *(.bss .bss.*)
    }

    .heap :
    {
        LINKER_kernel_heap =  ADDR(.heap);
        *(.heap)
        *(.heap.*)
        LONG(0)
    }

    . = ALIGN(4K); /* align to page size */
    __bss_end = .;
    __bss_size = __bss_end - __bss_start;
    __end = .;
}