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

    // Make sure it is all valid characters
    isvalid = ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '-' || c == '@' || c == '^' || c == '_' || c == '`' || c == '{' || c == '}' || c == '~';
    if (!isvalid)
    {
      return false;
    }
    pos++;
  }
  return true;
}

// Needs some work

/*
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

  // Update current cluster to point to next one
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
  seekpoint+=pos;
  return pos;
}

int32_t FAT12_quark::getsubdir(char *subdir_name, uint16_t *index, const char *path)
{
  const uint16_t beg = *index;
  uint32_t len = 0;

  if (path[beg] != '/')
  {
    return -1;
  }

  // Skip the root slash
  len++;
  while (path[beg + len] != '\0')
  {
    if (path[beg + len] == '/')
    {
      break;
    }

    ++len;
  }

  // Check if path is an intermediate directory
  if (path[beg + len] != '/')
  {
    return -2;
  }

  if (len > 12)
  {
    return -1;
  }

  memcpy(subdir_name, &path[beg], len);
  subdir_name[len] = '\0';

  *index = beg + len;
  return 0;
}

bool FAT12_quark::isinroot(const char *path)
{
  char subdir_name[13];
  uint16_t index = 0;

  return getsubdir(subdir_name, &index, path) < 0;
}

bool FAT12_quark::deleteentryinroot(char *name, bool is_file)
{
  uint16_t entry_index = 0;
  struct dir_entry entry;

  // Find the entry in the root directory
if (findrootdirectoryentry(&entry_index, name) < 0)
{
  return false;
}

movetorootdirectoryregion(entry_index);
entry = tsos->disk.getbytes(seekpoint, sizeof(entry), ((uint8_t *)&fat_entry));

dev.read(&entry, sizeof(entry));

// Check that we are deleting an entry of the right type
if (entry.attribute & VOLUME)
{
  return -1;
}
if ((is_file && (entry.attribute & SUBDIR)) || (!is_file && !(entry.attribute & SUBDIR)))
{
  return -1;
}

markrootentryasavailable(entry_index);
free_cluster_chain(entry.starting_cluster);

return true;
}

bool FAT12_quark::findrootdirectoryentry(uint16_t *entry_index, char *name)
{
  uint16_t i = 0;

  movetorootdirectoryregion(0);
  for (i = 0; i < bpb.root_entry_count; ++i)
  {
    struct dir_entry e;
    //dev.read(&e, sizeof(struct dir_entry));

    //Skip available entry
    if ((uint8_t)(e.name[0]) == AVAILABLE_DIR_ENTRY)
    {
      continue;
    }

    //Do not allow filename to start with a NULL character
    if (e.name[0] == 0)
    {
      break;
    }

    //Ignore any VFAT entry 
    if ((e.attribute & VFAT_DIR_ENTRY) == VFAT_DIR_ENTRY)
      continue;

    if (memcmp(name, e.name, sizeof(e.name)) == 0)
    {
      *entry_index = i;
      return true;
    }
  }

  return false;
}

uint32_t FAT12_quark::movetorootdirectoryregion(uint16_t entry_index)
{
  uint32_t pos = layout.start_root_directory_region;
  pos += layout.offset;
  pos += entry_index * 32;
  seekpoint += pos;
  return pos;
}

*/