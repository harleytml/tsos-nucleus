//By Tsuki Superior
#include <generic/sfs.hpp>
#include <generic/nucleus_instance.hpp>

SFS_quark::SFS_quark(void)
{
  name = "Simple File System";
}

bool SFS_quark::detectsystem(void)
{
  return true;
  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x03);
  const char *fsname = "SFS";
  for (uint8_t x = 0; x < 0x3; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
}

void SFS_quark::reset(void)
{
}

Array<String &> &SFS_quark::readdir(String &path)
{
  Array<String &> *tmp = (Array<String &> *)nullptr;
  return *tmp;
}

void SFS_quark::rename(String &path, char *newPath)
{
}

File SFS_quark::open(String &path)
{
  return File();
}

void SFS_quark::close(File file)
{
}

char *SFS_quark::read(File file)
{
  return "";
}

void SFS_quark::write(File file, char *data)
{
}

char *SFS_quark::readfile(String &path)
{
  return "";
}

void SFS_quark::writefile(String &path, char *data)
{
}

void SFS_quark::appendfile(String &path, char *data)
{
}

bool SFS_quark::exists(String &path)
{
  return false;
}

bool SFS_quark::isfilenamevalid(char *name)
{
  return true;
}
