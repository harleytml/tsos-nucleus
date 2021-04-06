#include <generic/default_font.hpp>

#ifdef __PERSONAL_COMPUTER__

Font get_default_font(void)
{
  return Font(fontdata, char_width, char_height);
}

#else

Font get_default_font(void)
{
  return Font();
}

#endif