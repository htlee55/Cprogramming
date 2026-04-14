#include <stdio.h>
#define SIZE 5

int main(void){
  int i;
  int s[SIZE];
  s[0] = 10;
  s[1] = 20;
  s[2] = 30;
  s[3] = 40;
  s[4] = 50;
  for(i=0;i<SIZE;i++)
    printf("s[%d]=%d\n",i,s[i]);
  return 0;
}
