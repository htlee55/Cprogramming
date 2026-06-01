#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;

	fp = fopen("alphabet.txt", "w");	// 파일을 쓰기 모드로 연다. 
	if (fp == NULL) {
		fprintf(stderr, "파일 alphabet.txt를 열 수 없습니다.\n");
		return 1;
	}

	char c;
	for (c = 'a'; c <= 'z'; c++) 	// ‘a'부터 ’z'까지 파일에 쓴다. 
		fputc(c, fp);

	fclose(fp);
	return 0;
}
