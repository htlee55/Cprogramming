#pragma once
#define NUM 6
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FISHTANK_WIDTH 100
#define FISHTANK_HEIGHT 200

// 게임 상태 구조체 정의
typedef struct {
    int fish;
    int water;
    int isAlive; // 1: alive, 0: dead
} FishTank;

// 전역 변수 정의
extern FishTank fishTanks[NUM];    // 물고기 어항 배열
extern int level;
extern int position;
extern bool running;
extern bool gameOver;
extern bool gameWin;
extern long startTime;
extern long lastUpdateTime;
// SDL 관련 변수
extern SDL_Window* window;          // SDL 창
extern SDL_Renderer* renderer;      // SDL 렌더러
extern TTF_Font* font;              // 폰트
extern SDL_Texture* fishTexture;    // 물고기 텍스처
// 오디오 관련 변수
extern SDL_AudioDeviceID audioDevice;  // 소리를 출력할 오디오 장치 식별자
extern SDL_AudioSpec wavSpec;              // wav 파일의 오디오 형식 정보
extern Uint8* wavBuffer;            // wav 파일의 실제 소리 데이터
extern Uint32 wavLength;               // 소리 데이터의 길이, 단위는 바이트

// 함수 프로토타입 선언
bool engine_init();                 // 엔진 초기화 함수
void initGame();                    // 게임 초기화 함수
void renderText(const char* text, int x, int y); // 텍스트 렌더링 함수
void renderFishTanks();             // 어항 렌더링 함수
void updateGame();                  // 게임 상태 업데이트 함수
void renderGame();                  // 게임 렌더링 함수
void cleanupGame();                 // 게임 종료 및 자원 해제 함수
void handleInput(SDL_Event* e);     // 입력 처리 함수
SDL_Texture* loadTexture(const char* path); // 텍스처 로드 함수

bool initAudio();                   // 오디오 초기화 함수
void playWaterSound();              // 물 주는 소리 재생 함수

