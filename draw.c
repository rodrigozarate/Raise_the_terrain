#include "terrain.h"

/**
* draw_function - draw a line
* @instance: var
* Return: void
*/

void draw_function(SDL_Instance instance)
{
        SDL_SetRenderDrawColor(instance.renderer, 0x00, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawLine(instance.renderer, 10,10, 10,100);
        SDL_RenderDrawLine(instance.renderer, 10,10, 100,100);
        SDL_RenderDrawLine(instance.renderer, 10,10, 100,10);
        SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(instance.renderer, 100,100, 10,100);
        SDL_RenderDrawLine(instance.renderer, 100,100, 100,10);
        SDL_RenderDrawLine(instance.renderer, 100,100, 200,200);
        SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0x00, 0xFF);
        SDL_RenderDrawLine(instance.renderer, 200,200, 200,300);
        SDL_RenderDrawLine(instance.renderer, 200,200, 300,200);
        SDL_RenderDrawLine(instance.renderer, 200,200, 300,300);
        SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0x00);
        SDL_RenderDrawLine(instance.renderer, 300,300, 400,400);
}
