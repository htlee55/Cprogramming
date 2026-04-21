#include <stdio.h>

int main(void)
{
	int number = 10;
	int *p = &number;		//변수의 주소를 추출하여 포인터 변수 p에 대입

	printf("변경 전 number = %d\n", number);
	*p = 20;
	printf("변경 후 number = %d\n", number);

	return 0;
}
