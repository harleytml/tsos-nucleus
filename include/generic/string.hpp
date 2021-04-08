/* By Tsuki Superior 
 *
 * String&
 * 
 * This is a version of the String& class made for TS/OS 
 */

#ifndef __TSOS_STRING_TYPE__
#define __TSOS_STRING_TYPE__

#include <generic/array.hpp>

extern "C"
{
  size_t strlen(const char *str);
  void *memcpy(void *dstptr, const void *srcptr, size_t size);
}

class String : public Array<char>
{
public:
  String(void);
  String(char *str);
  String(const char *str);
};

#endif