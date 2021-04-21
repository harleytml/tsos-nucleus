/* By Tsuki Superior
 * Generic EXT2 Quark
 *
 */

#pragma once

#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>

class EXT2_quark : public Filesystem_quark
{
public:
  EXT2_quark(void);
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

  class superblock_t
  {
  public:
    uint32_t inodes_count;
    uint32_t blocks_count;
    uint32_t blocks_superuser;
    uint32_t free_blocks;
    uint32_t free_inodes;
    uint32_t superblock_block;
    uint32_t block_size;
    uint32_t fragment_size;
    uint32_t blocks_per_group;
    uint32_t fragments_per_group;
    uint32_t inodes_per_group;
    uint32_t last_mount_time;
    uint32_t last_write_time;
    uint16_t mounts_since_fsck;
    uint16_t mounts_before_fsck;
    uint16_t magic;
    uint16_t state;
    uint16_t on_error;
    uint16_t version_minor;
    uint32_t last_fsck;
    uint32_t time_between_fsck;
    uint32_t creator_id;
    uint32_t version_major;
    uint16_t superuser;
    uint16_t supergroup;

    // The following fields are valid iff version_major >= 1
    uint32_t first_inode;
    uint16_t inode_size;
    uint16_t superblock_group;
    uint32_t optional_features;
    uint32_t required_features;
    uint32_t ro_features;
    uint32_t id[4];
    uint32_t name[4];
    uint8_t last_mount_path[64];
    uint32_t compression;
    uint8_t preallocate_files;
    uint8_t preallocate_directories;
    uint16_t unused;
    uint32_t journal_id[4];
    uint32_t journal_inode;
    uint32_t journal_device;
    uint32_t orphans_inode;
  } __attribute__((packed));

  class group_descriptor_t
  {
  public:
    uint32_t block_bitmap;
    uint32_t inode_bitmap;
    uint32_t inode_table;
    uint16_t free_blocs;
    uint16_t free_inodes;
    uint16_t directories_count;
    uint16_t pad;
    uint32_t unused[3];
  } __attribute__((packed));

  class ext2_fs_t
  {
  public:
    superblock_t *sb;
    group_descriptor_t *group_descriptors;
    uint8_t *device;
    uint32_t block_size;
    uint32_t inode_size;
    uint32_t num_block_groups;
  } __attribute__((packed));

  class ext2_inode_t
  {
  public:
    uint16_t type_perms;
    uint16_t uid;
    uint32_t size_lower;
    uint32_t last_access;
    uint32_t creation_time;
    uint32_t last_modified;
    uint32_t deletion_time;
    uint16_t gid;
    uint16_t hardlinks_count;
    uint32_t sectors_used;
    uint32_t flags;
    uint32_t os_specific1;
    uint32_t dbp[12];
    uint32_t sibp;
    uint32_t dibp;
    uint32_t tibp;
    uint32_t generation_number;
    uint32_t extended_attributes;
    uint32_t size_upper;
    uint32_t fragment_block;
    uint32_t os_specific2[3];
  } __attribute__((packed));

  class dentry_t
  {
  public:
    char *name;
    uint32_t inode;
    uint32_t type;
  } __attribute__((packed));

  class ext2_directory_entry_t
  {
  public:
    uint32_t inode;
    uint16_t entry_size;
    uint8_t name_len_low;
    uint8_t type;
    char name[];
  } __attribute__((packed));

  enum class Directory_entry : uint8_t
  {
    ENT_INVALID = 0,
    ENT_FILE = 1,
    ENT_DIRECTORY = 2
  };
};
