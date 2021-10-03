/*
* isometric.c - Create a isometric projection
* Author: Rodrigo Zárate Algecira
* Date: September 17, 2021
*/

/* Format to MAC use */
#include <SDL2/SDL.h>
#include <stdio.h>
#include "terrain.h"

/**
* main - Create a window to display lines
* @argc: arguments count
* @argv: arguments
* Return: 0
*/

int main(int argc, char **argv)
{
	SDL_Instance instance;

	if (argc != 2)
	{
		fprintf(stderr, "Usage terrain <file>\n");
		return (1);
	}

	if (init_instance(&instance, argv[1]) != 0)
		return (1);

	if (read_file(&instance) != 0)
		return (1);

	while ("Any string")
	{
		/* C, M, Y, K */
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_function(&instance);

		SDL_RenderPresent(instance.renderer);
	}

	clear_data(&instance);

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}

/**
* init_instance - Init window instance
* @instance: pointer
* @argv: char
* Return: 0
*/

int init_instance(SDL_Instance *instance, char *argv)
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Something happened... SDL_Error: %s\n", SDL_GetError());
		return (1);
	}
	else
	{
		instance->window = SDL_CreateWindow("SDL2 Isometric4",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (instance->window == NULL)
		{
			printf("Window crash! SDL_Error: %s\n", SDL_GetError());
			SDL_Quit();
			return (1);
		}
		else
		{
			instance->renderer = SDL_CreateRenderer(
			instance->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (instance->renderer == NULL)
			{
				SDL_DestroyWindow(instance->window);
				printf("Window crash! SDL_Error: %s\n",
				SDL_GetError());
				SDL_Quit();
				return (1);
			}
		}
	}
	instance->elevation = argv;
	instance->data = NULL;
	instance->xstep = 0;
	instance->ystep = 0;
	return (0);
}
