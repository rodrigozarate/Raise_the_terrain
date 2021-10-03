#include "terrain.h"

/**
* draw_function - draw a line
* @instance: var
* Return: void
*/

void draw_function(SDL_Instance *instance)
{
	int i, j;
	float centerx, centery, inclinationx, inclinationy;
	float x, y, z, startx, starty;

	centerx = SCREEN_WIDTH / 2.1;
	centery = SCREEN_HEIGHT / 2;
	inclinationx = 0.7;
	inclinationy = 0.5;

	drawframe(instance);

	SDL_SetRenderDrawColor(instance->renderer, 0x00, 0xFF, 0xFF, 0xFF);

	for (i = 0; i < instance->xstep; i++)
	{
		for (j = 0; j < instance->ystep; j++)
		{
			x = instance->data[i][j].x;
			y = instance->data[i][j].y;
			z = instance->data[i][j].z;
			startx = (inclinationx * x - inclinationx * y) +
					centerx;
			starty = (1 - inclinationy) * x + (1 - inclinationy) *
					y - z;
			if (i < instance->xstep - 1)
			{
				end_x(i, j, startx, starty, instance);
			}
			if (j < instance->ystep - 1)
			{
				end_y(i, j, startx, starty, instance);
			}
		}
	}
}


/**
* drawframe - draws a white frame
* @instance: pointer
*/

void drawframe(SDL_Instance *instance)
{
	SDL_SetRenderDrawColor(instance->renderer, 0xFF, 0xFF, 0xFF, 0x00);
	SDL_RenderDrawLine(instance->renderer, 10, 10, SCREEN_WIDTH - 10, 10);
	SDL_RenderDrawLine(instance->renderer, 10, 10, 10, SCREEN_HEIGHT - 10);
	SDL_RenderDrawLine(instance->renderer, 10, SCREEN_HEIGHT - 10,
			SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10);
	SDL_RenderDrawLine(instance->renderer, SCREEN_WIDTH - 10, 10,
			SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10);
}


/**
* end_x - set end row
* @startx: float
* @starty: float
* @i: int
* @j: int
* @instance: pointer
*/

void end_x(int i, int j, float startx, float starty, SDL_Instance *instance)
{
	float x, y, z, endx, endy;
	float centerx, inclinationx, inclinationy;

	centerx = SCREEN_WIDTH / 2.1;
	inclinationx = 0.7;
	inclinationy = 0.5;

	x = instance->data[i + 1][j].x;
	y = instance->data[i + 1][j].y;
	z = instance->data[i + 1][j].z;
	endx = (inclinationx * x - inclinationx * y) + centerx;
	endy = (1 - inclinationy) * x + (1 - inclinationy) * y - z;
	SDL_RenderDrawLine(instance->renderer, startx, starty, endx, endy);
}

/**
* end_y - set end col
* @startx: float
* @starty: float
* @i: int
* @j: int
* @instance: pointer
*/

void end_y(int i, int j, float startx, float starty, SDL_Instance *instance)
{
	float x, y, z, endx, endy;
	float centerx, inclinationx, inclinationy;

	centerx = SCREEN_WIDTH / 2.1;
	inclinationx = 0.7;
	inclinationy = 0.5;

	x = instance->data[i][j + 1].x;
	y = instance->data[i][j + 1].y;
	z = instance->data[i][j + 1].z;
	endx = (inclinationx * x - inclinationx * y) + centerx;
	endy = (1 - inclinationy) * x + (1 - inclinationy) * y - z;
	SDL_RenderDrawLine(instance->renderer, startx, starty, endx, endy);
}
