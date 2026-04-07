int add(int num1, int num2);
void o(int num);

int main(){
  int num;
  num = add(num,3);
  p(num);
  return 0;
}

int add(int num1, int num2){
  return num1 + num2;
}

void p(int num){
  printf("number is %d.\n", num);
}
