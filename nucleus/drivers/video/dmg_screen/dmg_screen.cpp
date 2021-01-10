//By Tsuki Superior
#include "dmg_screen.hpp"

DMG_SCREEN_driver::DMG_SCREEN_driver(void)
{

 //Also known as the Gameboy (Classic)
 name="Dot Matrix Game Screen";
 reset();
}

//This check is not needed, since the difference between a GBC and a DMG is a read only byte in the rom header, but I'll include it anyway 
BOOLEAN DMG_SCREEN_driver::detectsystem(void)
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
 tsos.boot.fission("NUCLEUS DETECTED HARDWARE FAULT");

 //So the compiler doesn't complain
 return FALSE;
}

void DMG_SCREEN_driver::reset(void)
{
 uint8_t * screen_control;

 //Disable the window and sprites, and set the buffers
 screen_control=(uint8_t *)0xff40;
 *screen_control=0x81;

 //Set the background scroll X to 0 
 screen_control=(uint8_t *)0xff43;
 *screen_control=0x00;

 //Set the background scroll Y to 0 
 screen_control=(uint8_t *)0xff42;
 *screen_control=0x00;

 //Set the color pallete
 //Value 0 == Color 0
 //The rest of the values == Color 3
 screen_control=(uint8_t *)0xff47;
 *screen_control=0xfc;

 //Reset that text cursor
 text_cursor=0; 
}

void DMG_SCREEN_driver::putchar(char c, Color bc, Color fc)
{
 //The DMG does support 4 colors, but its not possible to use them here, due to the small tile data memory that pretty much can't fit anything but the ASCII character set.
 text_buffer[text_cursor]=c;
}

uint16_t DMG_SCREEN_driver::gettextcursor(void)
{
 return text_cursor;
}

//So, this function is intereseting. The DMG is pretty much set up so that you can write plain text to a buffer and text appears on the screen.
//But there is a problem.
//The screen is 32*32 tiles (256*256 pixels). The rest of the screen is not shown.
//The visible screen is 20*18 tiles (160*144 pixels)
//So the screen driver must only be able to jump withen the range of the visible screen.
//The GBA suffers from a similar issue.
void DMG_SCREEN_driver::seektextcursor(uint16_t pos)
{
 text_cursor=pos;

 //Make sure it doesn't make it over that 20 tile width
 if((text_cursor%0x32)>0x14)
 {
  text_cursor+=0x32-(text_cursor%0x32);
 }

 //Prevent the cursor from passing over that 18 tile height
 while(text_cursor>=0x240)
 {
  text_cursor-=0x240;
 }
}

uint8_t DMG_SCREEN_driver::getscreenwidth(void)
{
 //The screen is 160*144, with 8*8 characters
 return 20;
}

uint8_t DMG_SCREEN_driver::getscreenheight(void)
{
 //The screen is 160*144, with 8*8 characters
 return 18;
}

char * DMG_SCREEN_driver::gettextbuffer(void)
{
 //Just in case the screen registers got changed for some reason
 switch(*((uint8_t *)0xff40)&0x8)
 {
  case 0:
   return (char *)0x9800;
  case 0x8:
   return (char *)0x9c00;
 }    
}

uint16_t DMG_SCREEN_driver::gettextbufferlength(void)
{
 return 0x168;
}

//You MUST set a font in this driver, because the DMG does not come with one
void DMG_SCREEN_driver::setfont(Font f)
{

 //The font must be 8*8 because DMG tiles are 8x8 (or 8*16, but only for sprites
 if(f.width == 8 && f.height == 8)
 {
  font=f
 
 }else{

 }
}