/* By Tsuki Superior
 * Abstract Filesystem Driver
 * 
 * To make a new Filesystem driver, simply have it inherit from this class
 * 
 */

#ifndef __TSOS_NUCLEUS_FILESYSTEM_DRIVER__
#define __TSOS_NUCLEUS_FILESYSTEM_DRIVER__

#include "generic/driver.hpp"
#include "generic/types.hpp"
#include "generic/filesystem_file.hpp"

class Filesystem_driver : public Driver
{
public:
  //Constructor
  Filesystem_driver(void);

  //Destructor
  ~Filesystem_driver();

  //Read the directory
  virtual char **readdir(char *path) = 0;

  //Rename a target
  virtual void rename(char *path, char *newPath) = 0;

  //Make sure a file actually exists
  virtual bool exists(char *path) = 0;

  //Open a file
  virtual File open(char *path) = 0;

  //Close a file
  virtual void close(File file) = 0;

  //Read a file
  virtual char *read(File file) = 0;

  //Write to a file
  virtual void write(File file, char *data) = 0;

  //Read from a file
  virtual char *readfile(char *path) = 0;

  //Write to a file
  virtual void writefile(char *path, char *data) = 0;

  //Append to a file
  virtual void appendfile(char *path, char *data) = 0;
};

#endif