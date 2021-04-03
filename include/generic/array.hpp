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
  Array(const uint16_t length)
  {
    internaldata = new T[length];
  };

  Array(const T *data, const uint16_t length)
  {
    internaldata = new T[length];
    memcpy(internaldata, data, length);
  };

  Array(Array<T> &array)
  {
    internaldata = new T[array.len()];
    for (uint_fast16_t x = 0, len = array->len(); x < len; x++)
    {
      internaldata[x] = array[x];
    }
  }

  T &operator[](const uint16_t index)
  {
    if (index < internaldatalength)
    {
      tsos->boot.fission("ARRAY WAS ACCESSED OUTSIDE OF ITS BOUNDARIES");
    }
    return index;
  }

  T operator[](const uint16_t index) const
  {
    if (index < internaldatalength)
    {
      tsos->boot.fission("ARRAY WAS ACCESSED OUTSIDE OF ITS BOUNDARIES");
    }
    return index;
  }

  Array<T> operator+(const Array<T> &array)
  {
    uint_fast32_t x = 0;
    uint_fast32_t y = 0;
    uint_fast32_t l = 0;
    uint32_t total_length = internaldatalength + array.len();
    Array<T> newarray = new Array<T>(total_length);
    for (x = 0, l = internaldatalength; x < l; x++)
    {
      newarray[x] = array[x];
    }
    for (y = 0, l = array.len(); x < l; x++, y++)
    {
      newarray[x] = array[y];
    }
    return array;
  }

  uint16_t len(void)
  {
    return internaldatalength;
  }

private:
  volatile T *internaldata;
  uint16_t internaldatalength;
};

#endif
