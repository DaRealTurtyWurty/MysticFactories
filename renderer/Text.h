#ifndef MYSTICFACTORIES_TEXT_H
#define MYSTICFACTORIES_TEXT_H

#include <SDL_ttf.h>
#include <cstdio>
#include <string>

TTF_Font* MF_LoadFont(const std::string& fontFile, int fontSize) {
    TTF_Font* font = TTF_OpenFont(("../" + fontFile + ".ttf").c_str(), fontSize);
    if (font == nullptr) {
        printf("Failed to load font: %s\n", TTF_GetError());
    }

    return font;
}

void MF_DrawText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y, const SDL_Color& color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        printf("Failed to create surface: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        printf("Failed to create texture: %s\n", TTF_GetError());
        return;
    }

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

#endif //MYSTICFACTORIES_TEXT_H
