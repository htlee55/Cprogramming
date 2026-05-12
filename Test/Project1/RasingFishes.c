#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>      // _kbhit(), _getch() 함수 사용

#define NUM 6
#define MAX_WATER 100
#define WATER_AMOUNT 3      //물주기 버튼을 누르면 어항에 추가되는 물의 양, 3씩 증가

//전역 변수 선언
int level;                  //게임 레벨, 1부터 시작, 레벨이 올라갈수록 물이 증발하는 속도가 빨라짐

//어항의 물 높이와 물고기 생존 여부를 저장하는 구조체
typedef struct {
    int waterLevel;         //물 높이
    int isAlive;           //물고기 생존 여부, 1이면 살아있음, 0이면 죽음
} FishTank;

FishTank fishTanks[NUM];    //어항 배열, NUM개의 어항이 존재
long prevElapsedTime;       //직전에 물준 시간
long totalElapsedTime;      //총 경과 시간
long startTime = 0;         //게임 시작 시간
FishTank* cursor;           //커서, 물을 줄 어항을 가리킴
int position = 0;           //선택된 어항 번호, 0,1,2,..NUM-1

// 함수 프로토타입 선언
void initData();
void update();
void render();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int checkWin();
void gotoxy(int x, int y);
int nonBlockingGetch();

// 입력 처리 관련 함수
void processInput();
void moveCursorLeft();
void moveCursorRight();
void giveWater();

int main(void) {
    int gameOver = 0;
    initData();             //게임 초기화 함수 호출
    startTime = clock();    //프로그램 실행 이후 현재까지 흐른 시간 저장
    cursor = fishTanks;     //물을 줄 어항을 표시하는 커서

    system("cls");

    while (!gameOver) {
		position = cursor - fishTanks;      //커서가 가리키는 어항 번호 계산
        // 키 입력 처리
		processInput();     //키 입력 처리 함수 호출
        //게임 데이터 업데이트
        update();
		position = cursor - fishTanks;      //커서가 가리키는 어항 번호 계산
        //게임 화면 출력
		render();                           //게임 화면 출력 함수 호출
        //레벨업 체크, 난이도 조정
        if (totalElapsedTime / 20 > level - 1) {
            level++;        //레벨업
            gotoxy(10, 3);
            printf("축하합니다. 레벨업이 되었습니다.");
        }
        //게임 승패 체크
        if (checkWin()) {
            gameOver = 1;
        }
        if (checkFishAlive() == 0) {
            gotoxy(2, 3);
            printf("모든 물고기가 죽었습니다. 게임을 종료합니다.");
            gameOver = 1;
        }
        prevElapsedTime = totalElapsedTime;
        Sleep(100);     //화면 깜빡임과 CPU 사용량을 줄이기 위한 짧은 대기
    }

    getchar();          //게임 화면 유지
    system("cls");
    return 0;
}

// 게임 초기화하는 함수
void initData() {
    level = 1;
    prevElapsedTime = 0;
    totalElapsedTime = 0;

    for (int i = 0; i < NUM; i++) {
        fishTanks[i].waterLevel = 100;    //물 높이의 범위 0 ~ 100
        fishTanks[i].isAlive = 1;         //물고기 생존 여부 초기화
    }
}

// 입력 처리 함수
void processInput() {
    int input;
    input = nonBlockingGetch();     // 키입력이 없으면 -1을 리턴
    if (input == -1) {
        return;                     // 입력이 없으면 아무 일도 하지 않고 종료
    }
    switch (input) {
    case 'j':                       // 왼쪽 이동
        moveCursorLeft();
        break;
    case 'l':                       // 오른쪽 이동
        moveCursorRight();
        break;
    case 'k':                       // 물주기
        giveWater();
        break;
    default:
        gotoxy(2, 12);
        printf("잘못된 입력입니다.");
        break;
    }
}

// 커서를 왼쪽으로 이동
void moveCursorLeft() {
    if (cursor > fishTanks) {
        cursor--;
    }
}

// 커서를 오른쪽으로 이동
void moveCursorRight() {
    if (cursor < fishTanks + NUM - 1) {
        cursor++;
    }
}

// 현재 커서가 가리키는 어항에 물주기
void giveWater() {
    cursor->waterLevel += WATER_AMOUNT;

    if (cursor->waterLevel > MAX_WATER) {
        cursor->waterLevel = MAX_WATER;
    }
}

// 데이터를 갱신하는 함수
void update() {
    //총 경과 시간, 초 단위로 표시
    totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
    //최근 경과 시간, 초 단위
    prevElapsedTime = totalElapsedTime - prevElapsedTime;
    decreaseWater(prevElapsedTime);         //어항의 물을 증발시키는 함수 호출
}

// 화면 출력 함수
void render() {
//    system("cls");

    //게임 이름 표시
    gotoxy(2, 2);
    printf("@물고기 키우기 프로젝트@");

    //게임 레벨 표시
    gotoxy(2, 3);
    printf("Level:%2d", level);

    //총 경과 시간 표시
    gotoxy(2, 4);
    printf("총 경과 시간: %ld초", totalElapsedTime);

    //최근 경과 시간 표시
    gotoxy(2, 5);
    printf("최근 경과 시간: %ld초", prevElapsedTime);

    //어항 번호 출력
    gotoxy(2, 6);
    for (int i = 0; i < NUM; i++) {
        printf(" %3d", i);
    }

    //어항 물높이 출력
    gotoxy(2, 7);
    for (int i = 0; i < NUM; i++) {
        printf(" %3d", fishTanks[i].waterLevel);
    }

	//어항 물고기 생존 여부 출력
	gotoxy(2, 9);
    for (int i = 0; i < NUM; i++) {
        if (fishTanks[i].isAlive) {
            printf("   O");
        } else {
            printf("   X");
        }
	}

    //현재 커서의 위치 표시
    gotoxy(2, 8);
    printf("   ");
    for (int i = 0; i < position; i++) {
        printf("    ");
    }
    printf("*");

    //키 입력 방법 고지
    gotoxy(2, 10);
    printf("왼쪽(j)  물주기(k)  오른쪽(l)");
}

//어항의 물을 증발시키는 함수
void decreaseWater(long elapsedTime) {
    for (int i = 0; i < NUM; i++) {
        fishTanks[i].waterLevel -= level * 3 * (int)elapsedTime;

        if (fishTanks[i].waterLevel < 0) {
			fishTanks[i].waterLevel = 0;    //물 높이는 0보다 낮아질 수 없음
			fishTanks[i].isAlive = 0;      //물고기 죽음 
        }
    }
}

// 게임 승리 여부를 체크하는 함수
int checkWin() {
    if (level == 5) {
        gotoxy(2, 3);
        printf("최고 레벨을 달성하셨습니다. 게임을 종료합니다.");
        return 1;
    }
    return 0;
}

//물고기가 모두 죽었는지를 확인하는 함수
int checkFishAlive() {
    for (int i = 0; i < NUM; i++) {
        if (fishTanks[i].isAlive > 0) {
            return 1;
        }
    }
    return 0;
}

//콘솔창 출력 위치 지정
void gotoxy(int x, int y)
{
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

//Non-blocking getch() 구현
int nonBlockingGetch() {
    if (_kbhit()) {
        return _getch();  // 키가 입력되었으면 입력된 키를 반환
    }
    return -1;            // 키가 입력되지 않았다면 -1을 반환
}