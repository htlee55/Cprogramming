int main(void)
{
	int i = 10;
	char c = 69;
	float f = 12.3;
	
	printf(“i의 값: %d\n”,i);
	printf(“i의 주소: %p\n”, &i);	// 변수 i의 주소 출력
	printf(“f의 주소: %p\n”, &f);	// 변수 f의 주소 출력
	return 0;
}
