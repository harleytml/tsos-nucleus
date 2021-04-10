/* By Tsuki Superior
 *
 * CXX Application Binary Interface
 * 
 * This file is being used as basically a small Libc
 * It implements memory allocation, and defines some basic functions
 * for the operation of normal code
 * 
 */

#ifndef __TSOS_CXXABI__
#define __TSOS_CXXABI__

#include <generic/types.hpp>

#define ATEXIT_MAX_FUNCS (128)

extern "C"
{

	typedef unsigned int uarch_t;

	struct atexit_func_entry_t
	{
		/*
	   * Each member is at least 4 bytes large. Such that each entry is 12bytes.
	   * 128 * 12 = 1.5KB exact.
	   */

		void (*destructor_func)(void *);
		void *obj_ptr;
		void *dso_handle;
	};

#ifdef __ARM_EABI__

	int __aeabi_atexit(void *arg, void (*func)(void *), void *d);
	void __aeabi_memcpy(void *dest, const void *src, size_t n);
	void __aeabi_memclr(void *dest, size_t n);
	void __aeabi_memmove(void *dest, const void *src, size_t n);
	void __aeabi_memset(void *dest, size_t n, int c);
	signed int __aeabi_idiv(signed int num, signed int den);

#endif

	int __cxa_atexit(void (*f)(void *), void *objptr, void *dso);
	void __cxa_finalize(void *f);
	void __cxa_pure_virtual();
	int __udivmodsi4(unsigned int num, unsigned int den, unsigned int *rem_p);
	unsigned int __udivsi3(unsigned int a, unsigned int b);
	void *memcpy(void *dstptr, const void *srcptr, size_t size);
	void *memset(void *bufptr, int value, size_t size);
	int memcmp(const void *aptr, const void *bptr, size_t size);
	void *memmove(void *dstptr, const void *srcptr, size_t size);
	int strcmp(const char *p1, const char *p2);
	size_t strlen(const char *str);
	size_t oct2bin(char *str, size_t size);
	char *itoa(int value, char *str, int base);
	int abs(int i);
}

namespace __cxxabiv1
{
	/* guard variables */

	/* The ABI requires a 64-bit type.  */
	__extension__ typedef int __guard __attribute__((mode(__DI__)));

	extern "C"
	{
		int __cxa_guard_acquire(__guard *);
		void __cxa_guard_release(__guard *);
		void __cxa_guard_abort(__guard *);
	}

}

#endif
