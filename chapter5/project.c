#include <stdio.h>
#include <time.h> // 헤더 파일 추가
#include <stdlib.h> // 헤더 파일 추가 

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
	// 난수 초기화
	srand(time(NULL));			//time(NULL): 1970년 1월 1일 0시 0분 0초(Epoch Time)부터 현재까지 경과된 시간을 초(second) 단위로 반환하는 함수
	int count = 0;
	// 변수 선언 및 초기화(맞힌 문제 개수)
	for (int i=1;i<=5;i++)
	{
		// 문제 출제 x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		// 문제 출력
		showQuestion(i,num1, num2);
		int answer = -1;
		// 답 입력
		scanf_s("%d",&answer);
		if (answer == -1) // 입력값이 -1일 때
		{
    		// break;
			exit(0);
		}
		else if ( answer == num1 * num2 )
		{
			//정답 출력
			sucess();
			// 맞힌 문제 개수 증가
			count++;
		}
		else // 정답을 못 맞혔을 때
		{
			//실패 출력
			fail();
		}
	}
	비밀번호 맞춘 갯수 출력
	printf("\n\n비밀번호 %d를 맞혔습니다.\n",count);
	return 0;
}

int getRandomNumber(int level){
	return rand()%(level*9)+1;
}
void showQuestion(int level, int num1, int num2){
}
void success(){
	printf("\n>> 정답입니다.\n");
}
void fail();{
		printf("\n>> 오답입니다.\n");
}
