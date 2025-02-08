#include <iostream>
#include <SDL3/SDL.h>
#include <vector>

#include <AI.hpp>
#include <check.hpp>
#include <window.hpp>
#include <movement.hpp>
#include <walls.hpp>

using namespace std;

int main(int argc, char *args[])
{
    SDL_Init(SDL_INIT_VIDEO);

    windowSize winSize;
    SDL_Window *myWindow = SDL_CreateWindow(
        winSize.name,
        winSize.width,
        winSize.height,
        0
    );
    SDL_Surface *myWindowSurface = SDL_GetWindowSurface(myWindow);

    SDL_Rect player;
    player.x = winSize.width / 2;
    player.y = winSize.height / 2;
    player.w = 10;
    player.h = 10;

    SDL_Rect brain;
    brain.x = 10;
    brain.y = 10;
    brain.w = 10;
    brain.h = 10;

    vector<SDL_Rect> walls = get_wall();

    SDL_Event event;
    bool quit = false;
    int timer = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    quit = true;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    movement(player, walls);
                    break;
            }
        }

        if (is_border(player) || is_touch(player, walls) || (brain.x == player.x && brain.y == player.y))
        {
            printf("end game\n");
            exit(0);
        }

        AI(brain, player, walls);
        
        SDL_FillSurfaceRect(myWindowSurface, NULL, SDL_MapRGB(myWindowSurface->format, 20, 20, 20));
        SDL_FillSurfaceRect(myWindowSurface, &player, SDL_MapRGB(myWindowSurface->format, 97, 89, 70));
        SDL_FillSurfaceRect(myWindowSurface, &brain, SDL_MapRGB(myWindowSurface->format, 97, 189, 70));
        for (const auto wall : walls) {
            SDL_FillSurfaceRect(myWindowSurface, &wall, SDL_MapRGB(myWindowSurface->format, 156, 156, 156));
        }

        SDL_UpdateWindowSurface(myWindow);
    }

    SDL_DestroyWindow(myWindow);
    SDL_Quit();
    return 0;
}