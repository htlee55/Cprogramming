#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    FILE* file;
    char name[20];
    int score, count = 0, total = 0;

    file = fopen("grades.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fscanf(file, "%s %d", name, &score) != EOF) {
        count++;
        total += score;
    }

    fclose(file);
    if (count > 0)
        printf("평균 성적: %.2f\n", (float)total / count);
    else
        printf("성적 데이터가 없습니다.\n");
    return 0;
}
