// This is basically a baseline loader, that doesn't do anything but jump to the kernel_main
  .align
  .section .text.boot
  .type _start, #function
  .global _start

_start:

  bl kernel_main

  _stop:
    b _stop
