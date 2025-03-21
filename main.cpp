#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "Renderer/Text.h"
#include "world/World.h"
#include "renderer/WorldRenderer.h"
#include "math/Vector2.h"

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

    Uint32 lastFrameTime = SDL_GetTicks();
    Uint32 frameCount = 0;
    Uint32 fpsLastTime = SDL_GetTicks();
    Uint32 fps = 0;
    float accumulatedTime = 0.0f;

    auto camera = new Camera();
    auto world = new World("Test World");
    auto worldRenderer = new WorldRenderer(world, camera);

    while (isRunning) {
        // Timing
        Uint32 currentFrameTime = SDL_GetTicks();
        float deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f; // in seconds
        lastFrameTime = currentFrameTime;

        accumulatedTime += deltaTime;

        // Input
        {
            Vector2 movement = {0, 0};

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
            }

            const Uint8* state = SDL_GetKeyboardState(nullptr);
            if (state[SDL_SCANCODE_W]) {
                movement.y = -1;
            } else if (state[SDL_SCANCODE_S]) {
                movement.y = 1;
            }

            if (state[SDL_SCANCODE_A]) {
                movement.x = -1;
            } else if (state[SDL_SCANCODE_D]) {
                movement.x = 1;
            }

            Player* player = world->GetPlayer();
            player->Move(movement.x * 16, movement.y * 16);
            camera->SetPosition(player->GetXPos() - SCREEN_WIDTH / 2 - 8, player->GetYPos() - SCREEN_HEIGHT / 2 - 8);
        }

        // Update
        {
            while (accumulatedTime >= UPDATE_INTERVAL) {
                world->Update();

                accumulatedTime -= UPDATE_INTERVAL;
            }
        }

        // Render
        {
            std::string fpsText = "FPS: " + std::to_string(fps);
            SDL_Color White = {255, 255, 255, 255};

            SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
            SDL_RenderClear(game.renderer);

            worldRenderer->Render(game.renderer);

            // Render
            MF_DrawText(game.renderer, font, fpsText, 5, 5, White);

            SDL_RenderPresent(game.renderer);
        }

        // Frame rate limiting
        {
            Uint32 frameTime = SDL_GetTicks() - currentFrameTime;
            if (frameTime < FRAME_TIME_MS) {
                SDL_Delay(FRAME_TIME_MS - frameTime);
            }

            frameCount++;
            if (SDL_GetTicks() - fpsLastTime >= 1000) { // If it's been a second (or more) since last check
                fps = frameCount - 1; // Subtract 1 because the frame count is incremented before this check
                frameCount = 0;
                fpsLastTime = SDL_GetTicks();
            }
        }
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.window);
    SDL_Quit();
}
