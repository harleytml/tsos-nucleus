//By Tsuki Superior
#include <generic/filesystem_file.hpp>

File::File(void)
{
  path = String();
  permissions = Permissions(false, false, false);
}

File::File(String &pa, Permissions &per)
{
  path = pa;
  permissions = per;
}

File::~File()
{
}