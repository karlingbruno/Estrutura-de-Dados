#include<stdio.h>
#include<stdlib.h>
int main(){
  int *p;
  int i,num;
  printf("Digite quantas posições você quer alocar:\n");
  scanf("%d",&num);
  p=(int *)calloc(num,sizeof(int));
  if(!p){
    printf("Espaço insuficiente\n");
  }
  for(i=0;i<num;i++){
    printf("Digite o valor da espaço número %d\n",i+1);
    scanf("%d",p+i);
  }
  for(i=0;i<num;i++){
    printf("Espaço de memória numero %d : %d\n",i,*(p+i));
  }
  free(p);

}
