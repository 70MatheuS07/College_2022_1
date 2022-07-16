#include <stdlib.h>
#include <stdio.h>

int mdc(int num);

int main(void) {

  int num,aux;
  int flag=0;
  scanf("%d", &num);
  
  while(num > 1){
    aux = mdc(num);
    //printf("%d\n", aux);
    num-=aux;
    if(flag == 0) flag = 1;
    else flag = 0;
  }

  if(flag)
    printf("true\n");
  else 
    printf("false\n");
  return 0;
}

int mdc(int num) {
  int numCopia;
     int resto;

  if(num % 2 == 0)
    return 1;

  numCopia = num;
    do {
      numCopia--;
        resto = num % numCopia;
    } while (resto != 0);

  //printf("%d\n", numCopia);
    return numCopia;
}