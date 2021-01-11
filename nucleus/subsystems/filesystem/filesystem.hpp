//By Tsuki Superior
#ifndef __TSOS_NUCLEUS_FILESYSTEM__
#define __TSOS_NUCLEUS_FILESYSTEM__

#define MAX_FILES_OPEN 0xff

#include "core.hpp"

//The main class controlling the filesystem
class Filesystem : public Module
{
public:
  //Constructor
  Filesystem(void);

  //Destructor
  ~Filesystem(void);

  //Read the contents of a directory
  char **readdir(char *path);

  //Rename a file or folder
  void rename(char *path, char *newPath);

  //Open a file
  Tsos_file open(char *path);

  //Close a file
  void close(Tsos_file file);

  //Read from a file
  uint8_t **read(Tsos_file file, uint32_t length);

  //Write to a file
  void write(Tsos_file file, uint8_t data[]);

  //Read all from a file
  uint8_t *readfile(char *path);

  //Write all to a file
  void writefile(char *path, uint8_t data[]);

  //Append to a file
  void appendfile(char *path, uint8_t data[]);

  //Detect if a file or folder exists
  BOOLEAN exists(char *path);

  //Create a directory
  void mkdir(char *path, File_permissions f);

  //Remove a directory
  void rmdir(char *path);

  //Checks if the user has permissions for the file
  void access(char *path);

private:
  //The current directory
  char *current_directory;

  //The files currently opened
  Tsos_file open_files[MAX_FILES_OPEN];

  //Filesystem driver
  Filesystem_driver *driver;
};

class Filesystem_driver : public Driver
{
public:
  //Constructor
  Filesystem_driver(void);

  //Destructor
  ~Filesystem_driver(void);

  //Read the directory
  virtual char **readdir(char *path){};

  //Rename a target
  virtual char *rename(char *path, char *newPath){};
};

//A file in Tsos
class Tsos_file
{
public:
  //Constructor of a null file
  Tsos_file(void);

  //Constructor
  Tsos_file(char *pa, File_permissions per);

  //The path of the file
  char *path;

  //The permissions the file was opened in
  File_permissions permissions;
};

class File_permissions
{
public:
  //Constructor
  File_permissions(BOOLEAN r, BOOLEAN w, BOOLEAN e);

  //Read permission
  BOOLEAN read;

  //Write permission
  BOOLEAN write;

  //Execute permission
  BOOLEAN execute;
};

#endif