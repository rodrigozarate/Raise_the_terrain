/*
* isometric.c - Create a isometric projection
* Author: Rodrigo Zárate Algecira
* Date: September 17, 2021
*/

/* Format to MAC use */
#include <SDL2/SDL.h>
#include <stdio.h>

/**
* main - Create a window to dosplay lines
* @argc: arguments count
* @args: arguments
* Return: 0
*/

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Something happened... SDL_Error: %s\n", SDL_GetError());
		return (1);
	}
	else
	{
		window = SDL_CreateWindow("SDL2 Isometric", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (window == NULL)
		{
			printf("Window crash... SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,
			0x00, 0x00, 0x00));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
return 0;
}
