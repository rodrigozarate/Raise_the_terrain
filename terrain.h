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

/**
* struct points - x,y,z points
* @x: 3d x
* @y: 3d y
* @z: 3d z
*/

typedef struct points
{
	float x;
	float y;
	float z;
} point;

/**
* struct SDL_Instance - SDL info
* @window: Viewport
* @renderer: Image execution
* @elevation: File with elevations
* @xstep: Steps in x axis
* @ystep: steps in y axis
* @data: x,y,z info
*/

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	char *elevation;
	int xstep;
	int ystep;
	point **data;
} SDL_Instance;

int init_instance(SDL_Instance *instance, char *argv);
void draw_function(SDL_Instance *instance);
void process_file(SDL_Instance *instance);
int read_file(SDL_Instance *instance);
void clear_data(SDL_Instance *instance);
int poll_events();

#endif /* _TERRAIN_H_ */
