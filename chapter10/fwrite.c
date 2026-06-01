#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int buffer[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	FILE* fp = NULL;

	fp = fopen("binary.bin", "wb");
	if (fp == NULL) {
		printf("binary.bin 파일을 열 수 없습니다.");
		return 1;
	}

	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);

	return 0;
}
