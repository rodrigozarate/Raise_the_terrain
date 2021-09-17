#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
	SDL_window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);

#endif
