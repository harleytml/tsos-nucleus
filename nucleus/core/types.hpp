//By Tsuki Superior
#ifndef __TSOS_INTERNAL_TYPES__
#define __TSOS_INTERNAL_TYPES__

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __UINT64_TYPE__ uint64_t;
typedef __INT8_TYPE__ int8_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;
typedef __INT64_TYPE__ int64_t;

typedef unsigned int uarch_t;

typedef __SIZE_TYPE__ size_t;

const uint8_t NULL = '\0';

// The machine's type
enum machine_type
{
  PERSONAL_COMPUTER,
  DOT_MATRIX_GAME,
  GAMEBOY_ADVANCED,
  PLAYSTATION_X,
  GENERIC,
  UNKNOWN
};


#endif