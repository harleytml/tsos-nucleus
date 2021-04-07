/* By Tsuki Superior
 * Generic FAT12 Quark
 *
 * The FAT12 will be used rarely these days, but you might see it on a floppy disk
 * 
 * This quark was adapted from fat12 linux driver by Francois Berder
 * Many thanks to him for making filesystem in a platform independent and 
 * simple way
 */

#ifndef __TSOS_FAT12_QUARK__
#define __TSOS_FAT12_QUARK__

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>

#define FIRST_CLUSTER_INDEX_IN_FAT (3)

class FAT12_quark : public Filesystem_quark
{
public:
  FAT12_quark(void);
  bool detectsystem(void) final;
  void reset(void) final;
  char **readdir(char *path) final;
  void rename(char *path, char *newPath) final;
  File open(char *path) final;
  void close(File file) final;
  char *read(File file) final;
  void write(File file, char *data) final;
  char *readfile(char *path) final;
  void writefile(char *path, char *data) final;
  void appendfile(char *path, char *data) final;
  bool exists(char *path) final;
  bool isfilenamevalid(char *name) final;

private:
  char *currentdirectory;
  File openfiles[128];

  class entry_handle
  {
  public:
    uint8_t mode;
    uint32_t pos_entry;
    uint16_t cluster;
    uint16_t offset;
    uint32_t remaining_bytes;
  } __attribute__((packed));

  class dir_entry
  {
  public:
    char name[11];
    uint8_t attribute;
    uint8_t reserved[10];
    uint8_t time[2];
    uint8_t date[2];
    uint16_t starting_cluster;
    uint32_t size;
  } __attribute__((packed));

  enum FILE_ATTRIBUTE
  {
    READ_ONLY = 0x01,
    HIDDEN = 0x02,
    SYSTEM = 0x04,
    VOLUME = 0x08,
    SUBDIR = 0x10,
    ARCHIVE = 0x20
  };

  class fat16_bpb
  {
  public:
    char oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reversed_sector_count;
    uint8_t num_fats;
    uint16_t root_entry_count;
    uint32_t sector_count;
    uint16_t fat_size; /* in sectors */
    uint32_t volume_id;
    char label[11];
    char fs_type[8];
  } __attribute__((packed));

  class fat16_layout
  {
  public:
    uint32_t offset;                      /**< offset in bytes of the FAT16 partition */
    uint32_t start_fat_region;            /**< offset in bytes of first FAT */
    uint32_t start_root_directory_region; /**< offset in bytes of root directory */
    uint32_t start_data_region;           /**< offset in bytes of data region */
    uint32_t data_cluster_count;          /**< Number of clusters in data region */
  } __attribute__((packed));

  fat16_layout layout;

  bool allocatecluster(uint16_t *new_cluster, uint16_t cluster);
  uint32_t getfatregion(uint16_t cluster);
};

#endif