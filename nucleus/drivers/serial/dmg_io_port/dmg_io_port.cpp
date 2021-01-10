//By Tsuki Superior
#include "dmg_io_port.hpp"

DMG_IO_PORT_driver::DMG_IO_PORT_driver(void)
{
 name="Dot Matrix Game IO Port";
}

//Well... there really is only one way to do this for any DMG driver
//This check is pointless to do, but I will do it anyway in the spirit of TS/OS
BOOLEAN DMG_IO_PORT_driver::detectsystem(void)
{

 //Check to make sure this isn't a Gameboy Color
 if(*((uint8_t *)0x147)!=0x80)
 {

  //This system is a Gameboy, or a Gameboy Pocket
  return TRUE;
 }

 //This was compiled wrong if the code reaches here
 //The header has the wrong value, because it was compiled for the Gameboy Color
 //So we will induce a fission
 tsos.boot.fission("KERNEL DETECTED HARDWARE FAULT");

 //So the compiler doesn't complain
 return FALSE;
}

//Serial on the DMG is lovely and simple
uint8_t DMG_IO_PORT_driver::exchangebyte(uint8_t b)
{
   
}

//Check if the device is there
BOOLEAN isdevicethere(void)
{

 //Get the serial data register
 uint8_t * SB = (uint8_t *)0xff01;

 //Get the screen control register
 uint8_t * SC = (uint8_t *)0xff02; 

 //Set the SB to a arbaitrary value
 *SB=0x00;

 //Set to internal clock (8192 Hz)
 *SC=0x81;

 //The time for a byte to transfer is very, very fast
 //8192 / 8 bits = 1024 clock cycles = 0.000977 seconds
 //You can pretty much count on it being done immediatly

 //If there is no console, the return is 0xff
 return *SB!=0xff;
}
