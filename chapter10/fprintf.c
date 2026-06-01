#include <stdio.h>

int main(void)
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    int num = 42;
    float f = 3.14;
    char str[] = "HelloWorld!";

    fprintf(file, "%d\n", num);
    fprintf(file, "%.2f\n", f);
    fprintf(file, "%s\n", str);

    fclose(file);
    return 0;
}
