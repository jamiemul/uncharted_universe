#pragma once
#include <memory>

struct SDLDeleter {
    void operator()(SDL_Window* window) const {
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    void operator()(SDL_Renderer* renderer) const {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
    }
    void operator()(SDL_Surface* surface) const {
        if (surface) {
            SDL_FreeSurface(surface);
        }
    }
    void operator()(SDL_Texture* texture) const {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }
};

using SDL2u_Window   = std::unique_ptr<SDL_Window,   SDLDeleter>;
using SDL2u_Renderer = std::unique_ptr<SDL_Renderer, SDLDeleter>;
using SDL2u_Surface  = std::unique_ptr<SDL_Surface,  SDLDeleter>;
using SDL2u_Texture  = std::unique_ptr<SDL_Texture,  SDLDeleter>;