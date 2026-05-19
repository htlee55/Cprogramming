#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>			
#include "engine.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool engine_init()
{
	// initialize SDL and create window
	if (SDL_Init(SDL_INIT_VIDEO) != 0)		
		return 0;
	//Create window
	window = SDL_CreateWindow("raisingFish", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);		//우리말로 렌더러는 화면에 그리는 도구라고 생각하면 된다. 창과 렌더러는 세트로 생각하면 된다.
	if (!window)
		return 0;
	// initialize other engine resources
	// ...
	return 1;
}

void engine_update()
{
	// Update game logic and other engine resources
	// ...
}

void engine_render()
{
	// Clear screen
	SDL_RenderClear(renderer);
	// Render game objects and other engine resources
	// ...
	// Update the window
	SDL_RenderPresent(renderer);
}

void engine_handle_event(SDL_Event* e)
{
	// Handle input events and other engine events
	// ...
}

void engine_cleanup()
{
	// Clean up engine resources
	// ...
	// Destroy renderer
	SDL_DestroyRenderer(renderer);
	// Destroy window
	SDL_DestroyWindow(window);
	// Quit SDL subsytems
	SDL_Quit();
}
