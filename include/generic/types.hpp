/* By Tsuki Superior
 * TS/OS types
 *
 * This is the types that TS/OS uses interally
 */

#pragma once

#define uint8_t __UINT8_TYPE__
#define uint16_t __UINT16_TYPE__
#define uint32_t __UINT32_TYPE__
#define uint64_t __UINT64_TYPE__

#define int8_t __INT8_TYPE__
#define int16_t __INT16_TYPE__
#define int32_t __INT32_TYPE__
#define int64_t __INT64_TYPE__

#define uint_fast8_t __UINT_FAST8_TYPE__
#define uint_fast16_t __UINT_FAST16_TYPE__
#define uint_fast32_t __UINT_FAST32_TYPE__
#define uint_fast64_t __UINT_FAST64_TYPE__

#define int_fast8_t __INT_FAST8_TYPE__
#define int_fast16_t __INT_FAST16_TYPE__
#define int_fast32_t __INT_FAST32_TYPE__
#define int_fast64_t __INT_FAST64_TYPE__

#define uintptr_t __UINTPTR_TYPE__
#define size_t __SIZE_TYPE__

#define NULL 0

typedef void (*func_ptr)(void);
