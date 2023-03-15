#include <stdio.h>

int soma (int a, int b);


int main(void) {
  int a, b, resultado;
  printf("Digite a e b\n");
  scanf("%d %d",&a,&b);
  
  resultado = soma(a , b);

  printf("%d", resultado);
  return 0;
}

int soma (int a, int b){
  int res = a + b;
  
  return res;
}