/* By Tsuki Superior
 *
 * This header file defines how syscalls are made
 */

#ifndef __TSOS_SYSABI__
#define __TSOS_SYSABI__

#include <generic/nucleus_instance.hpp>
#include <generic/types.hpp>

// The type defining syscalls
enum class syscall_t : uint16_t
{
  reboot = 0,
  shutdown = 1,
  fission = 2,
  getbytes = 3,
  setbytes = 4,
  getsectorsize = 5,
  commitall = 6,
  readdir = 7,
  rename = 8,
  open = 9,
  close = 10,
  read = 11,
  write = 12,
  readfile = 13,
  writefile = 14,
  appendfile = 15,
  exists = 16,
  mkdir = 17,
  rmdir = 18,
  access = 19,
  getkey = 20,
  waitkey = 21,
  spawn = 22,
  kill = 23,
  killall = 24,
  allocatememory = 25,
  freememory = 26,
  getbyte = 27,
  sendbyte = 28,
  isdevicereadytoreceive = 29,
  isdevicereadytotransmit = 30,
  playtone = 31,
  killsound = 32,
  reset = 33,
  putchar = 34,
  putstring = 35,
  getscreenwidth = 36,
  getscreenheight = 37,
  setfont = 38,
  clear = 39,
  settextbackgroundcolor = 40,
  settextforegroundcolor = 41,
  in8 = 42,
  out8 = 43,
  in16 = 44,
  out16 = 45,
  in32 = 46,
  out32 = 47
};

class Syscall_info
{
public:
  // The syscall that is going to be called
  syscall_t syscall;

  // A array of pointers to the data to be passed into the syscall
  void **input_data;

  // A array of pointer to be carried out
  void **output_data;

  bool inkernelmode;
} __attribute__((packed));

extern "C"
{
  // Call a syscall
  void callsyscall(Syscall_info &syscall_info);
}

#endif