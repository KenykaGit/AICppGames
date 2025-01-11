#include <SDL3/SDL.h>
#include <vector>

using namespace std;

void movement(SDL_Rect& player, const vector<SDL_Rect>& walls)
{
    SDL_Rect startPos = player;
    
    const Uint8 *keyStates = NULL;
    keyStates = SDL_GetKeyboardState(NULL);
    if(keyStates[SDL_SCANCODE_LEFT] || keyStates[SDL_SCANCODE_A]) player.x -= 10;
    if(keyStates[SDL_SCANCODE_RIGHT] || keyStates[SDL_SCANCODE_D]) player.x += 10;
    if(keyStates[SDL_SCANCODE_UP] || keyStates[SDL_SCANCODE_W]) player.y -= 10;
    if(keyStates[SDL_SCANCODE_DOWN] || keyStates[SDL_SCANCODE_S]) player.y += 10;

    if (is_touch(player, walls)) {
        player = startPos;
    }

    return;
}