#include <stdio.h>
int main(void) {
    int menu;
    while (1) 
    {
        printf("1.1부터 N까지의 합 구하기\n");
        printf("2.온도 판별하기\n");
        printf("3.나이 구분하기\n");
        printf("0.종료\n");
        scanf_s("%d", &menu);
        switch (menu) 
        {
            case 1: 
            {
                int n, sum = 0;
                printf("정수을 입력하세요: ");
                scanf_s("%d", &n);
                for (int i = 1; i <= n; i++) 
                {
                    sum += i;
                }
                printf("1부터 %d까지의 합: %d\n", n, sum);
                break;
            }
            case 2:
            {
                int temp;
                printf("온도를 입력하세요: ");
                scanf_s("%d", &temp);
                if (temp >= 0)
                {
                    printf("영상\n");
                }
                else
                {
                    printf("영하\n");
                }
                break;
            }
            case 3:
            {
                int age;
                printf("나이를 입력하세요: ");
                scanf_s("%d", &age);
                if (age >= 8 && age <= 13)
                {
                    printf("초등학생\n");
                }
                else if (age >= 14 && age <= 16) 
                {
                    printf("중학생\n");
                }
                else if (age >= 17 && age <= 19) 
                {
                    printf("고등학생\n");
                }
                else 
                {
                    printf("청소년이 아님\n");
                }
                break;
            }
            case 0:
            {
                printf("프로그램을 종료합니다.\n");
                return 0;
            }
            default:
            {
                printf("잘못된 번호입니다.\n");
            }    
        }
    }
    return 0;
}
