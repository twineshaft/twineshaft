/*
 * (C) 2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include "platform/clock.h"

#define _XOPEN_SOURCE 500 /* POSIX '95 */
#include <time.h>

struct ClockPOSIX {
	struct timespec ts;
};

Clock clock_create()
{
	struct ClockPOSIX* clock = malloc(sizeof(struct ClockPOSIX));

	return (Clock)clock;
}

void clock_destroy(Clock cl)
{
	struct ClockPOSIX* clock = (struct ClockPOSIX*)cl;
	free(clock);
}

int32_t clock_get_time(Clock cl)
{
	struct ClockPOSIX* clock = (struct ClockPOSIX*)cl;
}
