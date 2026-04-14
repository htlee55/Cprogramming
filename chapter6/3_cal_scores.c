#include <stdio.h>
#define STUDENTS 5

int main(void){
  int score[STUDENTS];
  int sum = 0;
  int average;
  for(int i=0;i<STUDENTS;i++){
    printf("학생들의 성적을 입력하시오: ");
    scanf("%d", &score[i]);
  }
  for(int i=0;i<STUDENTS;i++)
    sum += s[i];
  average = sum/STUDENTS;
  printf("성적 평균=%d\n",avarge);
  return 0;
}

