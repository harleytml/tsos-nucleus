/* By Tsuki Superior 
 *
 * Array 
 * 
 * This is a version of the Array class made for TS/OS 
 */

#pragma once

#include <generic/types.hpp>

extern "C"
{
  void *memcpy(void *dstptr, const void *srcptr, size_t size);
}

template <class T>
class Array
{
public:
  Array(void)
  {
    internaldata = (T *)nullptr;
    internaldatalength = 0;
  }

  Array(const uint16_t length)
  {
    internaldata = new T[length];
  };

  Array(T *data, const uint16_t length)
  {
    internaldata = data;
    internaldatalength = length;
  };

  Array(Array<T> &array)
  {
    internaldata = new T[array.len()];
    for (uint_fast16_t x = 0, len = array.len(); x < len; x++)
    {
      internaldata[x] = array[x];
    }
  }

  T &operator[](const uint16_t index)
  {
    if (index > internaldatalength)
    {
      while (true)
      {
      }
    }
    return internaldata[index];
  }

  T operator[](const uint16_t index) const
  {
    if (index > internaldatalength)
    {
      return 0;
    }
    return internaldata[index];
  }

  bool operator==(Array<T> &array) const
  {
    for (uint_fast16_t x = 0, length = len(); x < length; x++)
    {
      if (internaldata[x] != array[x])
      {
        return false;
      }
    }
    return true;
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

  void operator=(const Array<T> &array)
  {
    internaldata = array.raw();
    internaldatalength = array.len();
  }

  uint16_t len(void) const
  {
    return internaldatalength;
  }

  T *raw(void) const
  {
    return internaldata;
  }

protected:
  T *internaldata;
  uint16_t internaldatalength;
};
