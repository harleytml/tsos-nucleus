//By Tsuki Superior
#ifndef __TSOS_MODULE_CORE__
#define __TSOS_MODULE_CORE__

#include "generic/quark.hpp"
#include "generic/types.hpp"

// The base class of TS/OS nucleons
template <class T>
class Nucleon
{
public:
  // Constructor
  Nucleon(void)
  {
    name = "";
    quark = nullptr;
  };

  // Destructor
  ~Nucleon(){};

  // The full name of the nucleons's target
  char *name;

  // Attach a quark
  bool attachquark(T &d)
  {
    // The quark has to be for the right machine and run on that machine's configuration
    if (d.detectsystem())
    {
      quark = &d;
      name = quark->name;
      return true;
    }
    return false;
  };

  // Make sure the quark is set
  bool isquarkset(void)
  {
    return quark != nullptr;
  }

protected:
  T *quark;
};

#endif