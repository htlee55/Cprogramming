#include <stdio.h>

int main(void){
  int arr[5] = {10, 20, 30, 40, 50};
  int *p;
  
  p = arr;					      // arr은 배열 이름, arr은 &arr[0] 처럼 사용된다.
  							          // 그래서, p = arr; 이 가능하다.					
  printf("%p\n", arr);			
  printf("%p\n", &arr[0]);
  printf("%d\n", p[0]);	  // 그러면 p[0], p[1] 과 같이 배열 처럼 쓸 수 있다.
  printf("%d\n", p[1]);  
  return 0;
}
