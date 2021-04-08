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