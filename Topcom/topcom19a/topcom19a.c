#include <stdio.h>
#include <math.h>
// make -s ./main < test2.txt
int coprimo(long double, long double);

long double mdc(long double, long double);

int main(void) {
  long double a, b;
  int n;
  
  scanf("%d", &n);
  if(n==0){
    printf("false\n");
    return 0;
  }
  for(int i=0;i<n;i++){
    scanf("%Lf %Lf", &a, &b);
    if(coprimo(a, b)){
      printf("true\n");
    } else {
      printf("false\n");
    }
    printf("a:%Lf b:%Lf %Lf\n", a, b, mdc(a, b));
  }
  return 0;
}

int coprimo(long double a, long double b){
  if(mdc(a, b)==1){
    return 1;
  }
  return 0;
}

long double mdc(long double num1, long double num2) {
    long double resto;
    do {
        resto = fmod(num1, num2);
        num1 = num2;
        num2 = resto;
    } while (resto != 0);
    return num1;
}