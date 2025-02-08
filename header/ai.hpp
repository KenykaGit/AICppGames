#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include <delay.hpp>
#include <check.hpp>

using namespace std;

void AI(SDL_Rect &brain, const SDL_Rect &player, const vector<SDL_Rect> &walls)
{
    delayms(60);
    SDL_Rect tempBrain = brain;

    if (brain.x < player.x)
        tempBrain.x += 10;
    else if (brain.x > player.x)
        tempBrain.x -= 10;

    if (!is_touch(tempBrain, walls))
        brain.x = tempBrain.x;

    tempBrain = brain;

    if (brain.y < player.y)
        tempBrain.y += 10;
    else if (brain.y > player.y)
        tempBrain.y -= 10;

    if (!is_touch(tempBrain, walls))
        brain.y = tempBrain.y;
}