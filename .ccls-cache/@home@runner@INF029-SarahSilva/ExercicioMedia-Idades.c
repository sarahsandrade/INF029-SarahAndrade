#include <stdio.h>

int main(void) {
  int n;

  scanf("%d", &n);

  int i, media,idade[n];
  for(i=0,media=0;i<n;i++){
    scanf("%d", &idade[i]);
    media += idade[i];
  }
  media /= n;
  for(i=0;i<n;i++){
    if(media < idade[i])
      printf("%d ",idade[i]);
  }
  return 0;
}