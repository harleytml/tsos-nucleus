/* By Tsuki Superior
 *
 * CXX Application Binary Interface
 * 
 * This file is being used as basically a small Libc
 * It implements memory allocation, and defines some basic functions
 * for the operation of normal code
 * 
 */

#pragma once

#include <generic/types.hpp>

#define ATEXIT_MAX_FUNCS (128)
#define __INT_MIN__ (-__INT_MAX__ - 1)

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

	class uidiv_t
	{
	public:
		uint32_t quot;
		uint32_t rem;
	};

	int __aeabi_atexit(void *arg, void (*func)(void *), void *d);
	void __aeabi_memcpy(void *dest, const void *src, size_t n);
	void __aeabi_memclr(void *dest, size_t n);
	void __aeabi_memclr4(void *dest, size_t n);
	void __aeabi_memclr8(void *dest, size_t n);
	void __aeabi_memmove(void *dest, const void *src, size_t n);
	void __aeabi_memmove4(void *dest, const void *src, size_t n);
	void __aeabi_memmove8(void *dest, const void *src, size_t n);
	void __aeabi_memset(void *dest, size_t n, int c);
	signed int __aeabi_idiv(signed int num, signed int den);
	void __aeabi_uidivmod(uint32_t num, uint32_t den);
	uidiv_t aeabi_uidivmod(uint32_t num, uint32_t den);
	void uidiv_t_return(uidiv_t ret);

#endif

	int __cxa_atexit(void (*f)(void *), void *objptr, void *dso);
	void __cxa_finalize(void *f);
	void __cxa_pure_virtual();
	void *memcpy(void *dstptr, const void *srcptr, size_t size);
	void *memset(void *bufptr, int value, size_t size);
	int memcmp(const void *aptr, const void *bptr, size_t size);
	void *memshift(char *mem, int shift, size_t n);
	void *memmove(void *dstptr, const void *srcptr, size_t size);
	void *memchr(const void *str, int c, size_t n);
	int strcmp(const char *p1, const char *p2);
	char *itoa(int value, char *str, int base);
	size_t strlen(const char *str);
	size_t strnlen(const char *s, size_t maxlen);
	size_t oct2bin(char *str, size_t size);
	int abs(int i);
	int atoi(const char *str);
	int isspace(int c);
	int isdigit(int c);
	int isprint(int c);
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
