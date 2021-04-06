/* By Tsuki Superior
 * Abstract Process Quark
 * 
 * To make a new Process quark, simply have it inherit from this class
 * 
 * This quark class will most likely only have elf inherit from it
 * The only other class would be COFF or maybe some windows format
 */

#ifndef __TSOS_NUCLEUS_PROCESS_QUARK__
#define __TSOS_NUCLEUS_PROCESS_QUARK__

#include <generic/quark.hpp>
#include <generic/types.hpp>

class Process_quark : public Quark
{
public:
  Process_quark(void);

  ~Process_quark();

  virtual bool isvalidexecutable(char *path) = 0;
};

#endif