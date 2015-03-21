/*
 * (C) 2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include <stddef.h>

#include "platform/types.h"
#include "platform/glwindow.h"

#include "twineshaft.h"

int main(int argc, char* argv[])
{
	GLWindow w = glwindow_create("Main", (Size){640, 480});
	if (w == NULL)
		return 1;

	int retcode = twineshaft(w);

	glwindow_destroy(w);
	return retcode;
}
