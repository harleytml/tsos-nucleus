# TS/OS Syscalls

TOTAL SYSCALLS: 43

BOOT SYSCALLS:

 reboot:

  Reboot the system

 shutdown:

  Shutdown the system

 fission:

  Inform the user that a fatal system error has been encountered, and reboot

DISK SYSCALLS:

 getbytes:

  Get a length of bytes from a offset in the computer

 getsectorsize:

  Get the sector size of the disk

 commitall:

  Make sure all data to be written to the disk, is actually written to the disk

FILESYSTEM SYSCALLS:

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

INPUT SYSCALLS:

 getkey:

  Pop a key value off of the key buffer.

 waitkey:

  Wait for a key to be pressed.

PROCESS SYSCALLS:

 spawn:

  Spawn a process

 kill:

  Kill a process

 killall:

  Kill all processes

 allocatememory:

  Allocate memory

 freememory:
  
  Free memory

SERIAL SYSCALLS:

 exchangebyte:

  Exchange a byte with the other device

 isdevicethere:

  Check if a device is connected to this device

SOUND SYSCALLS:

 playtone:

  Play a tone of frequency and length

VIDEO SYSCALLS:

 reset:

  Reset the video system

 putchar:

  Put a single character on to the text buffer

 putstring:

  Put a C-Style string to the text buffer

 gettextcursor:

  Get the position of the text cursor

 seektextcursor:

  Set the position of the text cursor

 rseektextcursor:

  Set the position of the text cursor relatively

 gettextbuffer:

  Get a reference to the text buffer

 gettextbufferlength:

  Get the length of the text buffer

 getscreenwidth:

  Get the width of the screen

 getscreenheight:

  Get the height of the screen

 setfont:

  Set the font of the text system

 clear:

  Clear the text buffer

 scroll:

  Scroll the text buffer  

 settextbackgroundcolor:

  Set the background of the text system

 settextforegroundcolor:

  Set the foreground of the text system
