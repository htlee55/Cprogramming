
#include <stdio.h>

int function_with_return();	// 반환값이 있는 함수를 선언합니다.

int main(void)
{
	int ret = function_with_return();	// 반환값이 있는 함수를 호출합니다.
	printf("%d", ret);
	return 0;
}

int function_with_return()	//한글 주석으로 부탁합니다.
{
	printf("이 함수는 반환값이 있는 함수입니다.\n");
	return 10;
}

