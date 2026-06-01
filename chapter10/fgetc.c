#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;

	int c;	// 정수 변수에 주의한다. 

	fp = fopen("alphabet.txt", "r");
	if (fp == NULL) {
		printf("원본 파일 alphabet.txt를 열 수 없습니다.\n");
		return 1;
	}
	while ((c = fgetc(fp)) != EOF)
		putchar(c);

	fclose(fp);
	return 0;
}
