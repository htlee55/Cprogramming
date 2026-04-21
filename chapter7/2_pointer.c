#include <stdio.h>

int main(void)
{
	int number = 10;
	int *p;

	p = &number;

	printf("변수 number의 주소 = %p\n", &number);	// 변수의 주소 출력
	printf("포인터의 값 = %p\n", p);					// 포인터의 값 출력
	printf("변수 number의 값 = %d\n", number);		// 변수의 값 출력
	printf("포인터가 가리키는 값 = %d\n", *p);	// 포인터가 가리키는 곳의 값 출력

	return 0;
}	
