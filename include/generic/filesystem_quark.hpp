/* By Tsuki Superior
 * Abstract Filesystem Quark
 * 
 * To make a new Filesystem quark, simply have it inherit from this class
 * 
 */

#ifndef __TSOS_NUCLEUS_FILESYSTEM_QUARK__
#define __TSOS_NUCLEUS_FILESYSTEM_QUARK__

#include <generic/quark.hpp>
#include <generic/types.hpp>
#include <generic/filesystem_file.hpp>
#include <generic/array.hpp>
#include <generic/string.hpp>

class Filesystem_quark : public Quark
{
public:
  //Constructor
  Filesystem_quark(void);

  //Destructor
  ~Filesystem_quark();

  //Read the directory
  virtual Array<String &> readdir(String &path) = 0;

  //Rename a target
  virtual void rename(String &path, char *newPath) = 0;

  //Make sure a file actually exists
  virtual bool exists(String &path) = 0;

  //Open a file
  virtual File open(String &path) = 0;

  //Close a file
  virtual void close(File file) = 0;

  //Read a file
  virtual char *read(File file) = 0;

  //Write to a file
  virtual void write(File file, char *data) = 0;

  //Read from a file
  virtual char *readfile(String &path) = 0;

  //Write to a file
  virtual void writefile(String &path, char *data) = 0;

  //Append to a file
  virtual void appendfile(String &path, char *data) = 0;

  virtual bool isfilenamevalid(char *name) = 0;
};

#endif