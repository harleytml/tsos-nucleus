#include <generic/default_font.hpp>

Font get_default_font(void)
{
    return Font(reinterpret_cast<uint8_t *>(fontdata), char_width, char_height);
}
