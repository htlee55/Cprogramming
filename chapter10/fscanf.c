#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    FILE* file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }
    int num;
    float f;

    char str[20];
    fscanf(file, "%d", &num);
    fscanf(file, "%f", &f);
    fscanf(file, "%s", str);

    fclose(file);
    printf("정수: %d\n", num);
    printf("부동 소수점: %.2f\n", f);
    printf("문자열: %s\n", str);

    return 0;
}
