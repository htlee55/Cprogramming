#include <stdio.h>

int main(void)
{
	int temperature;
	// 온도 입력	
	printf("온도를 입력하세요: ");
	scanf("%d", &temperature);
	// 온도에 따른 날씨 출력
	if(temperature > 0)
	{
		printf("영상의 날씨입니다.\n");
	}
	else
	{
		printf("영하의 날씨입니다.\n");
	}
	printf("오늘의 온도는 %d도입니다.\n", temperature);
	return 0;
}
