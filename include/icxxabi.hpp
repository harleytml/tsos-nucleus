#ifndef __TSOS_ICXXABI__
#define __TSOS_ICXXABI__

#include "types.hpp"
#include "core.hpp"

#define ATEXIT_MAX_FUNCS 128

extern "C"
{

	typedef unsigned int uarch_t;

	struct atexit_func_entry_t
	{
		/*
	* Each member is at least 4 bytes large. Such that each entry is 12bytes.
	* 128 * 12 = 1.5KB exact.
	**/
		void (*destructor_func)(void *);
		void *obj_ptr;
		void *dso_handle;
	};

	int __cxa_atexit(void (*f)(void *), void *objptr, void *dso);

#ifdef __ARM_EABI__

	int __aeabi_atexit(void *arg, void (*func)(void *), void *d);

#endif

	void __cxa_finalize(void *f);
	void __cxa_pure_virtual();
	void *memcpy(void *dstptr, const void *srcptr, size_t size);
	void *memset(void *bufptr, int value, size_t size);
	int memcmp(const void *aptr, const void *bptr, size_t size);
	void *memmove(void *dstptr, const void *srcptr, size_t size);
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
