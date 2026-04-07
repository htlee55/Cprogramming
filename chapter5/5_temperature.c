#include <stdio.h>

double FtoC(double temp_f);	// 함수 원형 정의

int  main(void)
{
	double c, f;
	printf("화씨온도: ");
	scanf("%lf", &f);
	printf("섭씨온도: %lf \n\n", FtoC(f));
	return 0;
}

double FtoC(double temp_f)	// 함수 정의
{
	double  temp_c;
	temp_c = (5.0 * (temp_f - 32.0)) / 9.0;
	return temp_c;
}
