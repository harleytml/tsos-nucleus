//Driver by Tsuki Superior
#include "rs232.hpp"

RS232_driver::RS232_driver(void)
{

}

BOOLEAN RS232_driver::detectsystem(void)
{

 //Check to make sure this isn't a Gameboy Color
 if(*((uint8_t *)0x147)!=0x80)
 {

  //This system is a Gameboy, or a Gameboy Pocket
  return TRUE;
 }
 return FALSE;
}

//Serial on the DMG is lovely and simple
uint8_t RS232_driver::exchangebyte(uint8_t b)
{

 //Lets make sure that a reciving DMG is actually there

 //
 uint8_t * SB = (uint8_t *)0xff01;
 *SB=0x00
   
}
