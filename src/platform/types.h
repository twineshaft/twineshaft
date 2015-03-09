/*
 * (C) 2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#include "config.h"

#ifdef HAVE_STDBOOL_H
#  include <stdbool.h>
#else
#  define bool char
#  define true (!false)
#  define false (0)
#endif

#ifdef HAVE_STDINT_H
#  include <stdint.h>
#else
typedef signed char			int8_t;
typedef short				int16_t;
typedef int					int32_t;
typedef long long int		int64_t;
typedef unsigned int8_t		uint8_t;
typedef unsigned int16_t	uint16_t;
typedef unsigned int32_t	uint32_t;
typedef unsigned int64_t	uint64_t;
#endif

#endif // PLATFORM_TYPES_H
