//By Tsuki Superior
#include "./input_module.hpp"

Input::Input(void)
{
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