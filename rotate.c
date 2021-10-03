#include "terrain.h"

/**
* poll_events - receive keys stroke
* @instance: pointer
* Return: 0
*/

int poll_events(SDL_Instance *instance)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;
			if (key.keysym.scancode == 0x29)
				return (1);
			if (key.keysym.scancode == SDL_SCANCODE_LEFT)
				rotate(instance, -1);
			if (key.keysym.scancode == SDL_SCANCODE_UP)
				;
			if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
				rotate(instance, 1);
			if (key.keysym.scancode == SDL_SCANCODE_DOWN)
				;
			break;
		}
	}
	return (0);
}


/**
* rotate - rotate grid
* @instance: pointer
* @dir: int used to indicate direction
*/


void rotate(SDL_Instance *instance, int dir)
{
	int i, j;
	float x, y;
	float angle, newx, newy;

	/* side */
	if (dir == -1)
		angle = 1 * M_PI / 180;
	else if (dir == 1)
		angle = -1 * M_PI / 180;

	for (i = 0; i < instance->xstep; i++)
	{
		for (j = 0; j < instance->ystep; j++)
		{
			x = instance->data[i][j].x;
			y = instance->data[i][j].y;
			newx = x * cos(angle) - y * sin(angle);
			newy = x * sin(angle) + y * cos(angle);
			instance->data[i][j].x = newx;
			instance->data[i][j].y = newy;
		}
	}
}
