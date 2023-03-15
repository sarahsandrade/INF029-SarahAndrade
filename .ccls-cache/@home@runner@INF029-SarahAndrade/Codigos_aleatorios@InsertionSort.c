#include <stdio.h>
#define MAX 3
int main(void) {
  int aux,i, A[MAX];
  
  for(i=0;i<MAX; i++){
    printf("Digite o %d numero",i+1);
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<MAX;i++){
    aux= A[i];
    int j= i-1;
    while(j>=0 && A[j]>aux){
      A[j+1] = A[j];
      j = j-1;
    }
    A[j+1]=aux;
    
  }
  for(i=0;i<MAX; i++){
    printf("%d ",A[i]);
  }
  return 0;
}