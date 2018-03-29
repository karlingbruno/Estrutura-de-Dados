#include<stdio.h>
#include<stdlib.h>
int main(){
  int *p,*pNew;
  int i,j,a;
  p=(int *)calloc(5,sizeof(int));
  if(!p){
    printf("Espaço insuficiente\n");
  }
  j=0;
  printf("Digite os números desejados e para parar digte 0\n");
  do{
    scanf("%d",p+j);
    a=*(p+j);
    if((j+1)%5 == 0){
      int *pNew=realloc(p,(j+5) * sizeof(int));
      if(pNew){
        p=pNew;
        printf("Mais memória alocada\n");
      }else{
        printf("\nMemória insuficiente!\n");
        return 0;
      }
    }
    j++;
  }while(a != 0);
  for(i=0;i<j;i++){
    printf("Valor %d = %d \n",i,*(p+i));
  }
  free(p);
  free(pNew);
}
