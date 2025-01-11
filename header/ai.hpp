#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include <delay.hpp>

using namespace std;

void AI(SDL_Rect &brain, const SDL_Rect &player, const vector<SDL_Rect> &walls)
{
    if (brain.x != player.x || brain.y != player.y)
    {
        delayms(70);

        SDL_Rect tempBrain = brain;

        if (brain.x < player.x)
        {
            tempBrain.x += 10;
        }
        else if (brain.x > player.x)
        {
            tempBrain.x -= 10;
        }

        bool collision = false;
        for (const auto &wall : walls)
        {
            if (SDL_HasRectIntersection(&tempBrain, &wall))
            {
                collision = true;
                break;
            }
        }

        if (!collision)
        {
            brain.x = tempBrain.x;
        }

        tempBrain = brain;

        if (brain.y < player.y)
        {
            tempBrain.y += 10;
        }
        else if (brain.y > player.y)
        {
            tempBrain.y -= 10;
        }

        collision = false;
        for (const auto &wall : walls)
        {
            if (SDL_HasRectIntersection(&tempBrain, &wall))
            {
                collision = true;
                break;
            }
        }

        if (!collision)
        {
            brain.y = tempBrain.y;
        }
    }

    if (brain.x == player.x && brain.y == player.y)
    {
        printf("gg game over\n");
        delayms(500);
        exit(0);
    }
}