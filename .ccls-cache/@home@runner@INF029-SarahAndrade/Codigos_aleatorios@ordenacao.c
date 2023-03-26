#include <stdio.h>
#define TAM 10
int main(void) {
  int cont,i,j,menor,posicao;
  int vetor[TAM];

  for(i=0;i<TAM;i++){ 
    printf("Digite o numero da posicao %d: ",i);
    scanf("%d",&vetor[i]);}
  
  for(i=0;i<TAM-1;i++){// n-1
    menor= vetor[i];//(n-1).1
    posicao= i;//(n-1).1
  for(j=i+1;j<TAM;j++){//(n-1+1)(n-1)/2 = n(n-1)/2
    if(vetor[j]<menor){//n(n-1)/2
      menor= vetor[j];//n(n-1/)/4
      posicao=j;}//n(n-1)/4
    }
    vetor[posicao] = vetor[i];//n-1
    vetor[i] = menor;//n-1
  }
  for(i=0;i<TAM;i++){
    printf("%d ",vetor[i]);
    }
  
  return 0;
}