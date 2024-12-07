#include <iostream>
#include <SDL3/SDL.h>
#include <delay.hpp>

using namespace std;

struct windowSize
{
    int width = 700;
    int height = 400;
};

bool check_border(SDL_Rect snake)
{
    windowSize winSize;

    if (snake.x < 0 || snake.x > winSize.width - 10 ||
        snake.y < 0 || snake.y > winSize.height - 10)
    {
        return false;
    }
    return true;
    // false - если граница достигнута
    // true - если все окей
}

int main(int argc, char *args[])
{
    windowSize winSize;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *myWindow = SDL_CreateWindow(
        "Ai Game",
        winSize.width,
        winSize.height,
        0);
    SDL_Surface *myWindowSurface = SDL_GetWindowSurface(myWindow);
    SDL_FillSurfaceRect(
        myWindowSurface,
        NULL,
        SDL_MapRGB(
            myWindowSurface->format,
            20,
            20,
            20));

    SDL_Rect player;
    player.x = winSize.width / 2;
    player.y = winSize.height / 2;
    player.w = 10;
    player.h = 10;
    SDL_FillSurfaceRect(myWindowSurface, &player, SDL_MapRGB(myWindowSurface->format, 97, 89, 70));

    SDL_Rect brain;
    brain.x = 100;
    brain.y = 100;
    brain.w = 10;
    brain.h = 10;
    SDL_FillSurfaceRect(myWindowSurface, &brain, SDL_MapRGB(myWindowSurface->format, 97, 89, 70));

    SDL_UpdateWindowSurface(myWindow);
    SDL_Event event;
    bool quit = false;
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
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                case SDLK_a:
                    printf("left\n");
                    player.x -= 10;
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    printf("right\n");
                    player.x += 10;
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    printf("down\n");
                    player.y += 10;
                    break;
                case SDLK_UP:
                case SDLK_w:
                    printf("up\n");
                    player.y -= 10;
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        if (!check_border(player))
        {
            printf("end game\n");
        }

        if (brain.x != player.x)
        {
            delayms(70);
            if (brain.x < player.x)
            {
                brain.x += 10;
            }
            if (brain.x > player.x)
            {
                brain.x -= 10;
            }
        }

        if (brain.y != player.y)
        {
            delayms(70);
            if (brain.y < player.y)
            {
                brain.y += 10;
            }
            if (brain.y > player.y)
            {
                brain.y -= 10;
            }
        }

        if (brain.x == player.x && brain.y == player.y)
        {
            printf("gg game over\n");
            delaysc(1);
            return 0;
        }

        // if (brain.y != player.y)
        // {
        //     if (player.y > 0)
        //     {
        //         brain.y -= 10;
        //     }
        //     else if (player.y < 0)
        //     {
        //         brain.y += 10;
        //     }
        // }

        SDL_FillSurfaceRect(
            myWindowSurface,
            NULL,
            SDL_MapRGB(
                myWindowSurface->format,
                20,
                20,
                20));
        SDL_FillSurfaceRect(myWindowSurface, &player, SDL_MapRGB(myWindowSurface->format, 97, 89, 70));
        SDL_FillSurfaceRect(myWindowSurface, &brain, SDL_MapRGB(myWindowSurface->format, 97, 189, 70));
        SDL_UpdateWindowSurface(myWindow);
    }

    SDL_DestroyWindow(myWindow);
    SDL_Quit();
    return 0;
}