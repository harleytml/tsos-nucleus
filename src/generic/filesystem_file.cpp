//By Tsuki Superior
#include "generic/filesystem_file.hpp"

File::File(void)
{
  permissions = Permissions(false, false, false);
}

File::File(char *pa, Permissions per)
{
  path = pa;
  permissions = per;
}

File::~File()
{
}