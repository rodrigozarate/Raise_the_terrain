#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 640
#endif /* SCREEN_WIDTH */
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 480
#endif /* SCREEN_HEIGHT */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void draw_function(SDL_Instance instance);
int poll_events();

#endif /* _TERRAIN_H_ */
