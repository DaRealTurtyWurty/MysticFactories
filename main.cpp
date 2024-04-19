#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "Renderer/Text.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Game;

int main() {
    Game game;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    game.window = SDL_CreateWindow("Mystic Factories",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = MF_LoadFont("assets/fonts/Roboto-Regular", 24);
    if (font == nullptr) {
        return 1;
    }

    bool isRunning = true;
    SDL_Event event;

    Uint32 frameStart;
    Uint32 frameTime;
    float deltaTime;
    Uint32 lastFrame = 0;
    Uint32 fps;

    float accumulatedTime = 0.0f;

    while (isRunning) {
        frameStart = SDL_GetTicks();
        deltaTime = (frameStart - lastFrame) / 1000.0f;
        lastFrame = frameStart;

        accumulatedTime += deltaTime;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        isRunning = false;
                    }

                    break;
            }

            // Input
        }

        while (accumulatedTime >= DELAY_TIME) {
            // Update

            accumulatedTime -= DELAY_TIME;
        }

        fps = (Uint32)(1.0f / deltaTime) - 1;
        std::string fpsText = "FPS: " + std::to_string(fps);
        SDL_Color White = { 255, 255, 255, 255 };

        SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
        SDL_RenderClear(game.renderer);

        // Render
        MF_DrawText(game.renderer, font, fpsText, 5, 5, White);

        SDL_RenderPresent(game.renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
}
