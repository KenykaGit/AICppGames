#ifndef wallDef
#define wallDef

#include <SDL3/SDL.h>
#include <vector>

using namespace std;

vector<SDL_Rect> get_wall()
{
    SDL_Rect wall;
    wall.x = 200;
    wall.y = 50;
    wall.w = 200;
    wall.h = 10;

    SDL_Rect wall2;
    wall2.x = 400;
    wall2.y = 240;
    wall2.w = 200;
    wall2.h = 10;

    SDL_Rect wall3;
    wall3.x = 100;
    wall3.y = 200;
    wall3.w = 10;
    wall3.h = 150;

    vector<SDL_Rect> walls = {
        wall, wall2, wall3
    };

    return walls;
}

#endif