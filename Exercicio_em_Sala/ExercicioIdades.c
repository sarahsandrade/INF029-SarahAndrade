#include <stdio.h>

int main(void) {
  int n, soma = 0, i, media;
  
  printf("Digite o numero de idades:\n");
  scanf("%d", &n);
  
  printf("Digite as %d idades:\n",n);
  int idade[n];
  
  for(i=0;i<n;i++){
    scanf("%d", &idade[i]);
    soma += idade[i];      
  }
  
  media = soma/n;
  
  printf("A(s) idade(s) maiores que a media sao:\n");
  for(i=0;i<n;i++){
    if(media < idade[i])
      printf("%d\n",idade[i]);
  }
  
  return 0;
}