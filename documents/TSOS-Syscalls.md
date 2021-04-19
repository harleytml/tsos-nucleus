# TS/OS Syscalls

BOOT SYSCALLS:

```text
reboot:

Reboot the system

shutdown:

Shutdown the system

fission:

Inform the user that a fatal system error has been encountered, and reboot
```

DISK SYSCALLS:

```text
getbytes:

Get a length of bytes from a offset in the computer

setbytes:

Set a set off bytes at a offset in the computer

getsectorsize:

Get the sector size of the disk

commitall:

Make sure all data to be written to the disk, is actually written to the disk
```

FILESYSTEM SYSCALLS:

```text
readdir:

Return the contents of a directory

rename:

Rename a directory/file

open:

Mark a file as opened, and return a instance of file

close:

Close a file

read:

Read a number of bytes from a file

write:

Write a number of bytes to a file

readfile:

Read a entire file

writefile:

Write a entire file

appendfile:

Append data to a file

exists:

Check if file exists

mkdir:

Make a directory

rmdir:

Remove a directory

access:

Check if calling user has permissions to a file
```

INPUT SYSCALLS:

```text
getkey:

Pop a key value off of the key buffer.

waitkey:

Wait for a key to be pressed.
```

PROCESS SYSCALLS:

```text
spawn:

Spawn a process

kill:

Kill a process

killall:

Kill all processes
```

MEMORY SYSCALLS:

```text
allocatememory:

Allocate memory

freememory:

Free memory
```

SERIAL SYSCALLS:

```text
inbyte:

Send a byte to the other device

outbyte:

Gey a byte from the other device

isdevicereadytoreceive:

Checks if the connected device is ready to receive

isdevicereadytotransmit:

Checks if the connected device is ready to transmit
```

SOUND SYSCALLS:

```text
playtone:

Play a tone of frequency

killsound:

kill the audio
```

VIDEO SYSCALLS:

```text
reset:

Reset the video system

putchar:

Put a single character on to the text buffer

putstring:

Put a C-Style string to the text buffer

getscreenwidth:

Get the width of the screen

getscreenheight:

Get the height of the screen

setfont:

Set the font of the text system

clear:

Clear the text buffer

settextbackgroundcolor:

Set the background of the text system

settextforegroundcolor:

Set the foreground of the text system
```

IO SYSCALLS:

```text
in8:

Get a uint8_t from the port io

out8:

Send a uint8_t through the port io

in16:

Get a uint16_t from the port io

out16:

Send a uint16_t through the port io

in32:

Get a uint32_t from the port io

out32:

Send a uint32t through the port io

```
