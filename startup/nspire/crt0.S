    .align
    .section .text
    .type _start, #function
    .global _start

_start:

    bl kernel_main

    0:
      b 0b
