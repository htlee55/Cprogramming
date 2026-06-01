#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	FILE* fp;
	char str[100];

	fp = fopen("alphabet.txt", "r");

	if (fp == NULL) {
		printf("원본 파일 alphabet.txt를 열 수 없습니다.\n");
		return 1;
	}

	fgets(str, sizeof(str), fp);
	printf("%s \n", str);
	fclose(fp);
	return 0;
}
