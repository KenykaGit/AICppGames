#ifndef checkDef
#define checkDef

#include <SDL3/SDL.h>
#include <vector>
#include <window.hpp>

using namespace std;

bool is_border(SDL_Rect snake)
{
    windowSize winSize;

    if (snake.x < 0 || snake.x > winSize.width - 10 ||
        snake.y < 0 || snake.y > winSize.height - 10)
    {
        return true;
    }
    return false;
}

bool is_touch(const SDL_Rect& player, const vector<SDL_Rect>& walls) {
    for (const auto& wall : walls) {
        if (SDL_HasRectIntersection(&player, &wall)) {
            return true;
        }
    }
    return false;
}

#endif