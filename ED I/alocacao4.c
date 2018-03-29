#include<stdio.h>
#include<stdlib.h>
int * uniao(int *v1,int n1, int *v2, int n2){
  int n3,i;
  n3=n1+n2;
  int *v3;
  v3=(int *)calloc(n3,sizeof(int));
  for(i=0;i<n1;i++){
    *(v3+i)=*(v1+i);
  }
  for(i=0;i<n2;i++){
    *(v3+(i+n1))=*(v2+i);
  }
  return v3;

}
int main(){
  int n1,n2,i;
  int *v1,*v2,*v3,*x;
  printf("Digite o número de espaços de memória para V1\n");
  scanf("%d",&n1);
  v1=(int *)calloc(n1,sizeof(int));
  printf("Digite o número de espaços de memória para V2\n");
  scanf("%d",&n2);
  v2=(int *)calloc(n2,sizeof(int));
  printf("Digite os valores de v1\n");
  for(i=0;i<n1;i++){
    scanf("%d",v1+i);
  }
  printf("Digite os valores de v2\n");
  for(i=0;i<n2;i++){
    scanf("%d",v2+i);
  }
  x=uniao(v1,n1,v2  ,n2);
  printf("VETOR:\n");
  for(i=0;i<(n1+n2);i++){
    printf("%d\n",*(x+i));
  }
  free(x);
  free(v1);
  free(v2);
}
