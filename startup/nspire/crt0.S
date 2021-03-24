    .align
    .section .text
    .global _start

_start:

    bl kernel_main

    0:
      b 0b
