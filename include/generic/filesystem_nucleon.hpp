/* By Tsuki Superior
 * Generic Filesystem Nucleon
 *
 * The nucleon used to wrap filesystem quarks
 * 
 */

#ifndef __TSOS_NUCLEUS_FILESYSTEM_NUCLEON__
#define __TSOS_NUCLEUS_FILESYSTEM_NUCLEON__

#include <generic/nucleon.hpp>
#include <generic/types.hpp>
#include <generic/filesystem_quark.hpp>
#include <generic/filesystem_file.hpp>
#include <generic/filesystem_permissions.hpp>
#include <generic/current_config.hpp>

extern "C" int strcmp(const char *p1, const char *p2);

//The main class controlling the filesystem
class Filesystem : public Nucleon<Filesystem_quark>
{
public:
  //Constructor
  Filesystem(void);

  //Destructor
  ~Filesystem();

  //Read the contents of a directory
  Array<String &> &readdir(String &path);

  //Rename a file or folder
  void rename(String &path, String &newPath);

  //Open a file
  File open(String &path);

  //Close a file
  void close(File file);

  //Read from a file
  uint8_t *read(File file, uint32_t length);

  //Write to a file
  void write(File file, uint8_t data[]);

  //Read all from a file
  uint8_t *readfile(String &path);

  //Write all to a file
  void writefile(String &path, uint8_t data[]);

  //Append to a file
  void appendfile(String &path, uint8_t data[]);

  //Detect if a file or folder exists
  bool exists(String &path);

  //Create a directory
  void mkdir(String &path, Permissions f);

  //Remove a directory
  void rmdir(String &path);

  //Checks if the user has permissions for the file
  void access(String &path);

private:
  //The current directory
  char *current_directory;

  //The files currently opened
  File open_files[16];
};

#endif