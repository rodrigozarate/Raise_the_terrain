#include "terrain.h"

/**
* draw_function - draw a line
* @instance: var
* Return: void
*/

void draw_function(SDL_Instance *instance)
{

	int i, j;
	float x, y, z;
	float centerx;
	float centery;
	float inclinationx;
	float inclinationy;
	float startx, starty, endx, endy;

	centerx = SCREEN_WIDTH / 2;
	centery = SCREEN_HEIGHT / 2;
	inclinationx = 0.7;
	inclinationy = 0.7;

	SDL_SetRenderDrawColor(instance->renderer, 0x00, 0xFF, 0xFF, 0xFF);

	for (i = 0; i < instance->xstep; i++)
	{
		for (j = 0; j < instance->ystep; j++)
		{
			x = instance->data[i][j].x;
			y = instance->data[i][j].y;
			z = instance->data[i][j].z;
			startx = (inclinationx * (x - y)) + centerx;
			starty = ((1 - inclinationy) * (x + y) - z) + centery;
			if ( i < instance->xstep - 1)
			{
				x = instance->data[i + 1][j].x;
				y = instance->data[i + 1][j].y;
				z = instance->data[i + 1][j].z;
				endx = (inclinationx * (x - y)) + centerx;
				endy = ((1 - inclinationy) * (x + y) - z) +
					centery;
				SDL_RenderDrawLine(instance->renderer,
					startx, starty, endx, endy);
				printf("%f \n", startx);
				printf("%f \n", starty);
				printf("%f \n", endx);
				printf("%f \n", endy);
			}
			if ( i < instance->ystep - 1)
			{
				x = instance->data[i + 1][j].x;
				y = instance->data[i + 1][j].y;
				z = instance->data[i + 1][j].z;
				endx = (inclinationx * (x - y)) + centerx;
				endy = ((1 - inclinationy) * (x + y) - z) +
					centery;
				SDL_RenderDrawLine(instance->renderer,
					startx, starty, endx, endy);
			}
		}
	}

}
