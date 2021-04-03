    .align
    .section .text
    .type _start, #function
    .global _start

_start:

    bl kernel_main

    _stop:
      b _stop
