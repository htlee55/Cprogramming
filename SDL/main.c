#include <stdio.h> 
#include <SDL.h>
#include "engine.h"

// 전역 변수
SDL_Window* window;                 // SDL 창을 가리키는 포인터
SDL_Renderer* renderer;             // SDL 렌더러를 가리키는 포인터

int main(int argc, char** argv)
{
    if (!engine_init()) {
        printf("Error initializing engine: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Event event;
    int quit = 0;

    while (!quit) {
        // 이벤트 처리
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {// 윈도우의 x 표시를 누르면
                quit = 1;
            }
            // Pass events on queue
            engine_handle_event(&event);
        }
        // Update the engine
        engine_update();
        // Render the engine 
        engine_render();
    }
    // Clean up the engine
    engine_cleanup();

    return 0;
}
