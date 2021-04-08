#include <generic/string.hpp>

String::String(void)
{
  internaldata = nullptr;
  internaldatalength = 0;
}

String::String(char *str)
{
  internaldata = str;
  internaldatalength = strlen(str);
}

String::String(const char *str)
{
  uint32_t len = strlen(str);
  char *newstr = new char[len];
  memcpy(newstr, str, len);
  internaldata = newstr;
  internaldatalength = strlen(str);
}