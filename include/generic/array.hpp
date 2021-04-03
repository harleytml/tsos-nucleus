/* By Tsuki Superior 
 *
 * Array 
 * 
 * This is a version of the Array class made for TS/OS 
 */

#ifndef __TSOS_ARRAY_TYPE__
#define __TSOS_ARRAY_TYPE__

#include "generic/types.hpp"
#include "generic/nucleus_instance.hpp"

extern "C"
{
  void *memcpy(void *dstptr, const void *srcptr, size_t size);
}

template <class T>
class Array
{
public:
  Array(uint16_t length)
  {
    internaldata = new T[length];
  };

  Array(T *data, uint16_t length)
  {
    internaldata = new T[length];
    memcpy(internaldata, data, length);
  };

  Array(Array<T> &array)
  {
    internaldata = new T[array->len()];
    for (uint_fast16_t x = 0, len = array->len(); x < len; x++)
    {
      internaldata[x] = (*array)[x];
    }
  }

  T &operator[](uint16_t index)
  {
    if (index < internaldatalength)
    {
      tsos->boot.fission("ARRAY WAS ACCESSED OUTSIDE OF ITS BOUNDARIES");
    }
    return index;
  }

  uint16_t len(void)
  {
    return internaldatalength;
  }

private:
  T *internaldata;
  uint16_t internaldatalength;
};

#endif
