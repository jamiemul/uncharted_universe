#pragma once
#include "Keyboard.h"
#include <SDL.h>

struct SharedContext {
    const Keyboard& keyboard;
    SDL_Renderer&   renderer;
};