#pragma once

namespace TextureLoader {
    static SDL2u_Texture create1x1Texture(SDL_Renderer* renderer) {
        SDL2u_Texture texture = nullptr;
        SDL2u_Surface surface(SDL_CreateRGBSurface(0, 1, 1, 8, 0, 0, 0, 0));
        if (surface) {
            texture.reset(SDL_CreateTextureFromSurface(renderer, surface.get()));
            if (texture) {
                printf("Texture created successfully\n");
            } else {
                printf("Failed to create texture\n");
            }
        }
        return texture;
    }

    static SDL2u_Texture loadTexture(SDL_Renderer* renderer, const std::string& file, bool removeMagColor = false) {
        SDL2u_Texture texture = nullptr;
        SDL2u_Surface surface(SDL_LoadBMP(file.c_str()));
        if (surface) {
            if (removeMagColor) {
                SDL_SetColorKey(surface.get(), SDL_TRUE, 
                SDL_MapRGB(surface->format, Color::kMag.r, Color::kMag.g, Color::kMag.b));
            }
            texture.reset(SDL_CreateTextureFromSurface(renderer, surface.get()));
        } else {
            printf("Cannot find texture file: %s\n", file.c_str());
        }
        return texture;
    }
}




        //     if (texture) {
        //         printf("Texture loaded successfully: %s\n", file.c_str());
        //     } else {
        //         printf("Failed to create texture: %s\n", file.c_str());
        //     }
        // } else {
        //     printf("Cannot find texture file: %s\n", file.c_str());
        // }