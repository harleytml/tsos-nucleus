//By Tsuki Superior
#include "input_module.hpp"
#include "nucleus_instance.hpp"

Input::Input(void)
{
#ifdef __PERSONAL_COMPUTER__
  static AT_KEYBOARD_driver at_keyboard_driver = AT_KEYBOARD_driver();
  static XT_KEYBOARD_driver xt_keyboard_driver = XT_KEYBOARD_driver();

  if (attachdriver(at_keyboard_driver) ||
      attachdriver(xt_keyboard_driver))
  {
    return;
  }

#endif

#ifdef __GAMEBOY_ADVANCED__
  static GBA_GAMEPAD_driver gba_gamepad_driver = GBA_GAMEPAD_driver();

  attachdriver(gba_gamepad_driver);
#endif

#ifdef __RASPBERRY_PI_3__
  static RPI3_KEYBOARD_driver rpi3_keyboard_driver = RPI3_KEYBOARD_driver();

  attachdriver(rpi3_keyboard_driver);
#endif
}

Input::~Input(void)
{
}

key_identifier Input::getkey(void)
{
  return driver->getkey();
}

void Input::waitkey(void)
{
}
