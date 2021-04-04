#include "generic/default_font.hpp"

Font get_default_font(void)
{
  return Font(fontdata, char_width, char_height);
}