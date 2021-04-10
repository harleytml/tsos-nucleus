#include <generic/cxxabi.hpp>
#include <generic/nucleus_instance.hpp>

extern "C"
{

  atexit_func_entry_t __atexit_funcs[ATEXIT_MAX_FUNCS];
  uarch_t __atexit_func_count = 0;

  // Attention! Optimally, you should remove the '= 0' part and define this in your asm script.
  void *__dso_handle = 0;

  int __cxa_atexit(void (*f)(void *), void *objptr, void *dso)
  {
    if (__atexit_func_count >= ATEXIT_MAX_FUNCS)
    {
      return -1;
    };
    __atexit_funcs[__atexit_func_count].destructor_func = f;
    __atexit_funcs[__atexit_func_count].obj_ptr = objptr;
    __atexit_funcs[__atexit_func_count].dso_handle = dso;
    __atexit_func_count++;
    return 0;
  }

  void __cxa_finalize(void *f)
  {
    uarch_t i = __atexit_func_count;
    if (!f)
    {
      /*
		* According to the Itanium C++ ABI, if __cxa_finalize is called without a
		* function ptr, then it means that we should destroy EVERYTHING MUAHAHAHA!!
		*
		* TODO:
		* Note well, however, that deleting a function from here that contains a __dso_handle
		* means that one link to a shared object file has been terminated. In other words,
		* We should monitor this list (optional, of course), since it tells us how many links to 
		* an object file exist at runtime in a particular application. This can be used to tell 
		* when a shared object is no longer in use. It is one of many methods, however.
		**/
      //You may insert a prinf() here to tell you whether or not the function gets called. Testing
      //is CRITICAL!
      while (i--)
      {
        if (__atexit_funcs[i].destructor_func)
        {
          /* ^^^ That if statement is a safeguard...
				* To make sure we don't call any entries that have already been called and unset at runtime.
				* Those will contain a value of 0, and calling a function with value 0
				* will cause undefined behaviour. Remember that linear address 0, 
				* in a non-virtual address space (physical) contains the IVT and BDA.
				*
				* In a virtual environment, the kernel will receive a page fault, and then probably
				* map in some trash, or a blank page, or something stupid like that.
				* This will result in the processor executing trash, and...we don't want that.
				**/
          (*__atexit_funcs[i].destructor_func)(__atexit_funcs[i].obj_ptr);
        };
      };
      return;
    };

    while (i--)
    {
      /*
		* The ABI states that multiple calls to the __cxa_finalize(destructor_func_ptr) function
		* should not destroy objects multiple times. Only one call is needed to eliminate multiple
		* entries with the same address.
		*
		* FIXME:
		* This presents the obvious problem: all destructors must be stored in the order they
		* were placed in the list. I.e: the last initialized object's destructor must be first
		* in the list of destructors to be called. But removing a destructor from the list at runtime
		* creates holes in the table with unfilled entries.
		* Remember that the insertion algorithm in __cxa_atexit simply inserts the next destructor
		* at the end of the table. So, we have holes with our current algorithm
		* This function should be modified to move all the destructors above the one currently
		* being called and removed one place down in the list, so as to cover up the hole.
		* Otherwise, whenever a destructor is called and removed, an entire space in the table is wasted.
		**/
      if (__atexit_funcs[i].destructor_func == f)
      {
        /* 
			* Note that in the next line, not every destructor function is a class destructor.
			* It is perfectly legal to register a non class destructor function as a simple cleanup
			* function to be called on program termination, in which case, it would not NEED an
			* object This pointer. A smart programmer may even take advantage of this and register
			* a C function in the table with the address of some structure containing data about
			* what to clean up on exit.
			* In the case of a function that takes no arguments, it will simply be ignore within the
			* function itself. No worries.
			**/
        (*__atexit_funcs[i].destructor_func)(__atexit_funcs[i].obj_ptr);
        __atexit_funcs[i].destructor_func = 0;

        /*
			* Notice that we didn't decrement __atexit_func_count: this is because this algorithm
			* requires patching to deal with the FIXME outlined above.
			**/
      };
    };
  }

#ifdef __ARM_EABI__

  int __aeabi_atexit(void *arg, void (*func)(void *), void *d)
  {
    return __cxa_atexit(func, arg, d);
  }

  void __aeabi_memcpy(void *dest, const void *src, size_t n)
  {
    memcpy(dest, src, n);
  }

  void __aeabi_memclr(void *dest, size_t n)
  {
    memset(dest, 0, n);
  }

  void __aeabi_memmove(void *dest, const void *src, size_t n)
  {
    memmove(dest, src, n);
  }

  void __aeabi_memset(void *dest, size_t n, int c)
  {
    memset(dest, c, n);
  }

  signed int __aeabi_idiv(signed int num, signed int den)
  {
    signed int minus = 0;
    signed int v;

    if (num < 0)
    {
      num = -num;
      minus = 1;
    }
    if (den < 0)
    {
      den = -den;
      minus ^= 1;
    }

    v = __udivmodsi4(num, den, 0);
    if (minus)
      v = -v;

    return v;
  }

#endif

  int __cxa_guard_acquire(__cxxabiv1::__guard *g)
  {
    return !*(char *)(g);
  }

  void __cxa_guard_release(__cxxabiv1::__guard *g)
  {
    *(char *)g = 1;
  }

  void __cxa_guard_abort(__cxxabiv1::__guard *)
  {
  }

  void __cxa_pure_virtual()
  {
    tsos->boot.fission("PURE VIRTUAL FUNCTION CALLED");
  }

  int __udivmodsi4(unsigned int a, unsigned int b, unsigned int *rem)
  {
    int d = __udivsi3(a, b);
    *rem = a - (d * b);
    return d;
  }

  unsigned int __udivsi3(unsigned int a, unsigned int b)
  {
    typedef union
    {
      unsigned int i;
      float f;
    } fu;

    unsigned int d, t, s0, s1, s2, r0, r1;
    fu u0, u1, u2, u1b, u2b;

    if (b > a)
      return 0;

    // Compute difference in number of bits in S0.
    u0.i = 0x40000000;
    u1b.i = u2b.i = u0.i;
    u1.i = a;
    u2.i = b;
    u1.i = a | u0.i;
    t = 0x4b800000 | ((a >> 23) & 0xffff);
    if (a >> 23)
    {
      u1.i = t;
      u1b.i = 0x4b800000;
    }
    u2.i = b | u0.i;
    t = 0x4b800000 | ((b >> 23) & 0xffff);
    if (b >> 23)
    {
      u2.i = t;
      u2b.i = 0x4b800000;
    }
    u1.f = u1.f - u1b.f;
    u2.f = u2.f - u2b.f;
    s1 = u1.i >> 23;
    s2 = u2.i >> 23;
    s0 = s1 - s2;

    b <<= s0;
    d = b - 1;

    r0 = 1 << s0;
    r1 = 0;
    t = a - b;
    if (t <= a)
    {
      a = t;
      r1 = r0;
    }

#define STEP(n) \
  case n:       \
    a += a;     \
    t = a - d;  \
    if (t <= a) \
      a = t;
    switch (s0)
    {
      STEP(31)
      STEP(30)
      STEP(29)
      STEP(28)
      STEP(27)
      STEP(26)
      STEP(25)
      STEP(24)
      STEP(23)
      STEP(22)
      STEP(21)
      STEP(20)
      STEP(19)
      STEP(18)
      STEP(17)
      STEP(16)
      STEP(15)
      STEP(14)
      STEP(13)
      STEP(12)
      STEP(11)
      STEP(10)
      STEP(9)
      STEP(8)
      STEP(7)
      STEP(6)
      STEP(5)
      STEP(4)
      STEP(3)
      STEP(2)
      STEP(1)
    case 0:;
    }
    r0 = r1 | (r0 - 1 & a);
    return r0;
  }

  void *memcpy(void *dstptr, const void *srcptr, size_t size)
  {
    uint8_t *dst = (uint8_t *)dstptr;
    const uint8_t *src = (const uint8_t *)srcptr;
    for (size_t i = 0; i < size; i++)
    {
      dst[i] = src[i];
    }
    return dstptr;
  }

  void *memset(void *bufptr, int value, size_t size)
  {
    uint8_t *buf = (uint8_t *)bufptr;
    for (size_t i = 0; i < size; i++)
    {
      buf[i] = (uint8_t)value;
    }
    return bufptr;
  }

  int memcmp(const void *aptr, const void *bptr, size_t size)
  {
    const uint8_t *a = (const uint8_t *)aptr;
    const uint8_t *b = (const uint8_t *)bptr;
    for (size_t i = 0; i < size; i++)
    {
      if (a[i] < b[i])
      {
        return -1;
      }
      else
      {
        if (b[i] < a[i])
        {
          return 1;
        }
      }
    }
    return 0;
  }
  void *memmove(void *dstptr, const void *srcptr, size_t size)
  {
    uint8_t *dst = (uint8_t *)dstptr;
    const uint8_t *src = (const uint8_t *)srcptr;
    if (dst < src)
    {
      for (size_t i = 0; i < size; i++)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      for (size_t i = size; i != 0; i--)
      {
        dst[i - 1] = src[i - 1];
      }
    }
    return dstptr;
  }

  int strcmp(const char *p1, const char *p2)
  {
    const uint8_t *s1 = (const uint8_t *)p1;
    const uint8_t *s2 = (const uint8_t *)p2;
    uint8_t c1, c2;
    do
    {
      c1 = (uint8_t)*s1++;
      c2 = (uint8_t)*s2++;
      if (c1 == NULL)
      {
        return c1 - c2;
      }
    } while (c1 == c2);
    return c1 - c2;
  }

  size_t strlen(const char *str)
  {
    size_t pos = 0;
    while (str[pos++] != 0)
    {
    }
    return pos;
  }

  size_t oct2bin(char *str, size_t size)
  {
    int n = 0;
    char *c = str;
    while (size-- > 0)
    {
      n *= 8;
      n += *c - '0';
      c++;
    }
    return n;
  }

  char *itoa(int value, char *str, int base)
  {
    char *rc;
    char *ptr;
    char *low;
    // Check for supported base.
    if (base < 2 || base > 36)
    {
      *str = '\0';
      return str;
    }
    rc = ptr = str;
    // Set '-' for negative decimals.
    if (value < 0 && base == 10)
    {
      *ptr++ = '-';
    }
    // Remember where the numbers start.
    low = ptr;
    // The actual conversion.
    do
    {
      // Modulo is negative for negative value. This trick makes abs() unnecessary.
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
      value /= base;
    } while (value);
    // Terminating the string.
    *ptr-- = '\0';
    // Invert the numbers.
    while (low < ptr)
    {
      char tmp = *low;
      *low++ = *ptr;
      *ptr-- = tmp;
    }
    return rc;
  }

  int abs(int i)
  {
    return i < 0 ? -i : i;
  }
}

void *operator new(size_t size)
{
  return tsos->memory.allocatememory(size);
}

void *operator new[](size_t size)
{
  return tsos->memory.allocatememory(size);
}

void operator delete(void *p)
{
  tsos->memory.freememory(p);
}

void operator delete[](void *p)
{
  tsos->memory.freememory(p);
}
