#ifndef MYSTICFACTORIES_TEXTURE_H
#define MYSTICFACTORIES_TEXTURE_H

#include <SDL_render.h>
#include <SDL_image.h>
#include <string>

SDL_Texture* MF_LoadTexture(SDL_Renderer* renderer, const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

void MF_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* dst) {
    SDL_RenderCopy(renderer, texture, nullptr, dst);
}

void MF_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h) {
    SDL_Rect dst = {x, y, w, h};
    MF_RenderTexture(renderer, texture, &dst);
}

void MF_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    MF_RenderTexture(renderer, texture, x, y, w, h);
}

#endif //MYSTICFACTORIES_TEXTURE_H
