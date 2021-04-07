//By Tsuki Superior
#include <generic/fat12.hpp>
#include <generic/nucleus_instance.hpp>

FAT12_quark::FAT12_quark(void)
{
  name = "File Allocation Table 12";
  layout = fat16_layout();
}

bool FAT12_quark::detectsystem(void)
{
  return true;
  uint8_t *diskfsname = tsos->disk.getbytes(0x4f, 0x05);
  const char *fsname = "FAT12";
  for (uint8_t x = 0; x < 0x5; x++)
  {
    if ((uint8_t)fsname[x] != diskfsname[x])
    {
      return false;
    }
  }
}

void FAT12_quark::reset(void)
{
}

char **FAT12_quark::readdir(char *path)
{
  return (char **)NULL;
}

void FAT12_quark::rename(char *path, char *newPath)
{
}

File FAT12_quark::open(char *path)
{
  return File();
}

void FAT12_quark::close(File file)
{
}

char *FAT12_quark::read(File file)
{
  return "";
}

void FAT12_quark::write(File file, char *data)
{
}

char *FAT12_quark::readfile(char *path)
{
  return "";
}

void FAT12_quark::writefile(char *path, char *data)
{
}

void FAT12_quark::appendfile(char *path, char *data)
{
}

bool FAT12_quark::exists(char *path)
{
  return true;
}

bool FAT12_quark::isfilenamevalid(char *name)
{
  bool isvalid = false;
  char c;
  uint16_t pos = 0;
  while (name[pos])
  {
    c = name[pos];
    isvalid = ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '-' || c == '@' || c == '^' || c == '_' || c == '`' || c == '{' || c == '}' || c == '~';
    if (!isvalid)
    {
      return false;
    }
    pos++;
  }
  return true;
}

bool FAT12_quark::allocatecluster(uint16_t *new_cluster, uint16_t cluster)
{
  uint16_t next_cluster = FIRST_CLUSTER_INDEX_IN_FAT;
  do
  {
    next_cluster++;
    uint16_t fat_entry;
    tsos->disk.setbytes(getfatregion(next_cluster), sizeof(fat_entry), ((uint8_t *)&fat_entry));

    // Mark it as end of file
    if (fat_entry == 0)
    {
      fat_entry = 0xffff;
      tsos->disk.setbytes(getfatregion(next_cluster), sizeof(fat_entry), ((uint8_t *)&fat_entry));
      break;
    }
  } while (next_cluster < layout.data_cluster_count - FIRST_CLUSTER_INDEX_IN_FAT);

  if (next_cluster == layout.data_cluster_count)
  {
    return false;
  }

  /* Update current cluster to point to next one */
  if (cluster != 0)
  {
    tsos->disk.setbytes(getfatregion(cluster), sizeof(next_cluster), ((uint8_t *)&next_cluster));
  }

  *new_cluster = next_cluster;
  return true;
}

uint32_t FAT12_quark::getfatregion(uint16_t cluster)
{
  uint32_t pos = layout.start_fat_region;
  pos += layout.offset;
  pos += cluster * 2;
  return pos;
}