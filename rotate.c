#include "terrain.h"

/**
* poll_events - receive keys stroke
* Return: 0
*/

int poll_events()
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
                                printf("37 left\n");
                        if (key.keysym.scancode == SDL_SCANCODE_UP)
                                printf("up\n");
                        if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
                                printf("right\n");
                        if (key.keysym.scancode == SDL_SCANCODE_DOWN)
                                printf("down\n");
                        break;
                }
        }
        return (0);
}

