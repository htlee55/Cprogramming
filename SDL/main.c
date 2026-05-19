//spaceGame1
#include <stdio.h> 
#include <SDL.h>
#include "header.h"

// 전역 변수
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[]) {

    if (!engine_init()) {
        printf("Error initializing engine: %s\n", SDL_GetError());
        return 1;
    }

    initGame();

    while (running) {           // Game Loop
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            handleInput(&event);
        }
        // update the game
        updateGame();
        // render the game
        renderGame();
        // update the window
        SDL_Delay(100);
    }
    // cleanup the game
    cleanupGame();

    return 0;
}
