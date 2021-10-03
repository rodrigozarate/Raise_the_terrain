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
	centery = SCREEN_HEIGHT / 4;
	inclinationx = 0.5;
	inclinationy = 0.5;

	SDL_SetRenderDrawColor(instance->renderer, 0x00, 0xFF, 0xFF, 0xFF);

	for (i = 0; i < instance->xstep; i++)
	{
		switch (i)
		{
			case 0:
				SDL_SetRenderDrawColor(instance->renderer,
					0x00, 0xFF, 0xFF, 0xFF);
				break;
			case 1:
				SDL_SetRenderDrawColor(instance->renderer,
					0xFF, 0x00, 0xFF, 0xFF);
				break;
			case 2:
				SDL_SetRenderDrawColor(instance->renderer,
					0xFF, 0xFF, 0x00, 0xFF);
				break;
                        case 3:
                                SDL_SetRenderDrawColor(instance->renderer,
                                        0xFF, 0xFF, 0xFF, 0x00);
                                break;
			case 4:
                                SDL_SetRenderDrawColor(instance->renderer,
                                        0x00, 0xFF, 0xFF, 0xFF);
                                break;
                        case 5:
                                SDL_SetRenderDrawColor(instance->renderer,
                                        0xFF, 0x00, 0xFF, 0xFF);
                                break;
			case 6: 
                                SDL_SetRenderDrawColor(instance->renderer,
                                        0xFF, 0xFF, 0x00, 0xFF);
                                break;
                        case 7: 
                                SDL_SetRenderDrawColor(instance->renderer,
                                        0xFF, 0xFF, 0xFF, 0x00);
                                break;
			default:
				SDL_SetRenderDrawColor(instance->renderer,
					0xFF, 0xFF, 0xFF, 0x00);
				break;
		}
		for (j = 0; j < instance->ystep; j++)
		{
			x = instance->data[i][j].x;
			y = instance->data[i][j].y;
			z = instance->data[i][j].z;
			startx = (inclinationx * x - inclinationx * y) +
					centerx;
			starty = (1 - inclinationy) * x + (1 - inclinationy) *
					y - z;
			if ( i < instance->xstep - 1)
			{
				x = instance->data[i + 1][j].x;
				y = instance->data[i + 1][j].y;
				z = instance->data[i + 1][j].z;
				endx = (inclinationx * x - inclinationx * y) +
						centerx;
				endy = (1 - inclinationy) * x +
					(1 - inclinationy) * y - z;
				SDL_RenderDrawLine(instance->renderer,
					startx, starty, endx, endy);
			}
			if ( j < instance->ystep - 1)
			{
				x = instance->data[i][j + 1].x;
				y = instance->data[i][j + 1].y;
				z = instance->data[i][j + 1].z;
				endx = (inclinationx * x - inclinationx * y) +
					centerx;
				endy = (1 - inclinationy) * x +
					(1 - inclinationy) * y - z;
				SDL_RenderDrawLine(instance->renderer,
					startx, starty, endx, endy);
			}
		}
	}

}
