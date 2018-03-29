#include<stdio.h>
#include<stdlib.h>
typedef struct{
  char nome[50];
  char endereco[100];
  int matricula;
}estudante;
int main(){
  estudante *p;
  int i,num;
  printf("Digite quantos alunos você deseja cadastrar:\n");
  scanf("%d",&num);
  p=(estudante *)calloc(num,sizeof(estudante));
  if(!p){
    printf("Espaço insuficiente\n");
  }
  for(i=0;i<num;i++){
    printf("Digite o Nome do estudante número %d\n",i+1);
    __fpurge(stdin);
    fgets((p+i)->nome,50,stdin);
    printf("Digite o endereço do estudante número %d\n",i+1);
    fgets((p+i)->endereco,100,stdin);
    printf("Digite o numero da matricula do estudante número %d\n",i+1);
    scanf("%d",&((p+i)->matricula));

  }
  for(i=0;i<num;i++){
    printf("\nDados do Aluno %d:\n",i+1);
    printf("Nome: %sEndereço: %sMatrícula: %d\n",(p+i)->nome,(p+i)->endereco,(p+i)->matricula);
  }
  free(p);

}
