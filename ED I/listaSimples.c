#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100

typedef struct produto{
  int codigo;
  char nome[TAM];
  float preco;
}produto;

typedef struct nodo{
  produto produt;
  struct nodo *prox;
}nodo;

nodo *inserir(nodo *v){
  nodo *u=(nodo *)calloc(1,sizeof(nodo));
  printf("Digite o código do produto :\n");
  scanf("%d",&u->produt.codigo);
  getchar();
  printf("Digite o nome do produto :\n");
  fgets(u->produt.nome,TAM,stdin);
  printf("Digite o preço do produto :\n");
  scanf("%f",&u->produt.preco);
  system("clear");
  u->prox=v;
  printf("Produto cadastrado!\n");
  system("clear");
  return(u);

}
void *excluir(nodo *u){
  int codego,i=0,contador=0;
  nodo *j=u;
  nodo *x=u;
  nodo *aux=NULL;
  printf("Digite o código do produto para ser excluido\n");
  scanf("%d",&codego);
  for(;j->prox != NULL;j=j->prox){
    contador++;
  }
  for(;x->produt.codigo != codego;x=x->prox){
    i++;
  }
  if(i>0 && i<contador){
    for(int j=0;j<i;j++){
      if(j==(i-1)){
        u->prox=u->prox->prox;
        return(u);
      }
      else{
        u=u->prox;
      }
    }
  }
  else if(i == contador && i!=0){
    for(int j=0;j<i;j++){
      if(j+1==i){
        u->prox = NULL;
        return(u);
      }
      else{
        u=u->prox;
      }
    }
  }
  else if(i == 0 && contador == 0){
    u=NULL;
    return(u);
  }
  else if(i == 0 && contador != 0){
    u=u->prox;
    return(u);

  }
}
void exibir(nodo *n){
  system("clear");
  if(n==NULL){
    printf("Lista Vazia!\n");
  }else{
  for(;n != NULL;n = n->prox){
    printf("Código : %d\n",n->produt.codigo);
    printf("Nome : %s",n->produt.nome);
    printf("Preço : %f\n\n",n->produt.preco);

  }
  }
  sleep(4);
  system("clear");

}
int main(){
  nodo *n = NULL;
  int x;
  do{
    printf("\t\tMENU\nInserir : 1\nExcluir : 2\nExibir : 3\nSair : 0\n");
    scanf("%d",&x);
    switch (x) {
      case 1:
        n=inserir(n);
        break;
      case 2:
        n=excluir(n);
        break;
      case 3:
        exibir(n);
        break;
      case 0:
        break;
      default:
        printf("Opção invalida\n");
        break;
    }

  }while(x != 0);
free(n);



}
