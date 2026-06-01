#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp1, * fp2;

	fp1 = fopen("alphabet.txt", "r");
	fp2 = fopen("copy.txt", "w");
	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	int c;
	// fp1에서 한 글자씩 읽어서 fp2로 쓴다. 
	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
