#include <stdio.h>
#define MAX 3
int main(void) {
  int aux,i, A[MAX];
  
  for(i=0;i<MAX; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<MAX;i++){
    aux= A[i];
    int j= i-1;
    while(i>=0 && A[i]>aux){
      A[j+1] = A[j];
      j = j+1;
    }
  }
  return 0;
}