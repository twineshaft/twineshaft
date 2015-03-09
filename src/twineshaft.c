/*
 * (C) 2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include "twineshaft.h"
#include "platform/glwindow.h"

#include "render/render.h"

int32_t twineshaft(GLWindow wind)
{
	render_init(glwindow_get_size(wind));

	while(true) {
		int32_t e = EVENT_NONE;
		while ((e = glwindow_get_event(wind)) != EVENT_NONE) {
			if (e == EVENT_RESIZE)
				render_resize(glwindow_get_size(wind));
			else if (e == EVENT_QUIT)
				return 0;
			//else
			//	handle_input();
		}

		render_block();
		glwindow_flush(wind);
	}
}
