/* By Tsuki Superior
 * Copyright (C) 2017  Francois Berder <fberder@outlook.fr>
 *
 * Generic FAT16 Quark
 *
 * The FAT16 will be used rarely these days, but you might see it on a floppy disk
 * 
 * This quark was adapted from fat16 linux driver by Francois Berder
 * Many thanks to him for making filesystem in a platform independent and 
 * simple way
 * 
 * https://github.com/francois-berder/fat16
 */

#pragma once

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>

#include <generic/string.hpp>

#define FIRST_CLUSTER_INDEX_IN_FAT ((3))
#define MAX_BYTES_PER_CLUSTER ((32768LU))
#define VFAT_DIR_ENTRY ((0x0F))
#define AVAILABLE_DIR_ENTRY ((0xE5))

extern "C"
{
  void *memcpy(void *dstptr, const void *srcptr, size_t size);
  void *memset(void *bufptr, int value, size_t size);
}

class FAT16_quark : public Filesystem_quark
{
public:
  FAT16_quark(void);
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

  enum class FILE_ATTRIBUTE : uint8_t
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
  fat16_bpb bpb;

  uint32_t seekpoint;

  // Needs some work
  ///*
  bool allocatecluster(uint16_t *new_cluster, uint16_t cluster);
  uint32_t movetofatregion(uint16_t cluster);
  int32_t getsubdir(char *subdir_name, uint16_t *index, char *path);
  bool isinroot(char *path);
  bool deleteentryinroot(char *name, bool is_file);
  bool findrootdirectoryentry(uint16_t *entry_index, char *name);
  uint32_t movetorootdirectoryregion(uint16_t entry_index);
  void markrootentryasavailable(uint16_t entry_index);
  bool lastentryinrootdirectory(uint16_t entry_index);
  void freeclusterchain(uint16_t cluster);
  uint32_t readfromhandle(class entry_handle *handle, void *buffer, uint32_t count);
  uint32_t getnextcluster(uint16_t *next_cluster, uint16_t cluster);
  uint32_t movetodataregion(uint16_t cluster, uint16_t offset);

  //*/
};
