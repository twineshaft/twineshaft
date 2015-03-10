/*
 * (C) 2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include "testutils.h"

#include <stdio.h>

int tests_failed;
int tests_succeded;

void test_begin()
{
	tests_failed = 0;
	tests_succeded = 0;
	puts("");
}

void test_result(int succeeded, const char* name)
{
	if (succeeded) {
		printf("\e[42m\e[97mPASS\e[0m: %s\n", name);
		tests_succeded++;
	} else {
		printf("\e[101m\e[97mFAIL\e[0m: %s\n", name);
		tests_failed++;
	}
}

int test_retcode()
{
	printf("\nFinished: %d tests passed, %d failed.\n\n", tests_succeded,
		tests_failed);
	return tests_failed;
}
