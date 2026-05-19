//#pragma once		

#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>	

// 화면 크기
#define WIDTH 800
#define HEIGHT 600

// 함수원형(function prototype) 선언

bool engine_init();
void engine_update();
void engine_render();
void engine_handle_event(SDL_Event* e);
void engine_cleanup();

#endif
