#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<unistd.h>
// essa ultima biblioteca serve somente pra tirar o warning do "sleep"
typedef struct {
  int codigo;
  char nome[20];
  float preco;
}produto;

typedef struct nodo{
  produto info;
  struct nodo *next;
  struct nodo *prev;
}nodo;

typedef struct lista{
  int nItens;
  nodo *first;
  nodo *last;
}lista;

nodo *inserir(int *j,nodo *n,lista *hue){
  system("clear");
  nodo *u;
  u=(nodo *)calloc(1,sizeof(nodo));
  printf("Digite o código do produto :\n");
  scanf("%d",&u->info.codigo);
  getchar();
  printf("Digite o nome do produto :\n");
  fgets(u->info.nome,20,stdin);
  printf("Digite o preço do produto :\n");
  scanf("%f",&u->info.preco);
  if(*j == 0){
    u->next=NULL;
    u->prev=NULL;
    hue->first=u;
    hue->last=u;
    (*j)++;

  }else{
    u->next=NULL;
    u->prev=n;
    n->next=u;
    hue->last=u;
    (*j)++;
  }
  system("clear");
  printf("Produto cadastrado!\n");
  sleep(3);
  system("clear");
  return(u);

}
void exibir(nodo *j,int *x){
  system("clear");
  if(*x == 0){
    printf("Lista vazia!\n");
    sleep(3);
    system("clear");
  }else{
    for(;j != NULL;j=j->prev){
      printf("Código : %d\n",j->info.codigo);
      printf("Nome : %s",j->info.nome);
      printf("Preço : %.3f\n\n",j->info.preco);
    }
    sleep(3);
    system("clear");
  }
}
nodo *excluir(int *j,nodo *n,lista *hue){
  system("clear");
  if(*j == 0){
    system("clear");
    printf("Lista Vazia!\n");
    sleep(3);
    n=NULL;
    return(n);
  }else{
    int x;
    printf("Digite o código do produto para excluir:\n");
    scanf("%d",&x);
    for(;n->prev != NULL;n=n->prev){
      if(n->info.codigo == x){
        break;
      }
    }
    if(n == hue->first && n == hue->last){
      n=NULL;
      printf("Excluido!\n");
      sleep(3);
      system("clear");
      (*j)--;
      hue->last=n;
      hue->first=n;
      return(n);
    }
    else if(n == hue->first && n != hue->last){
      n=n->next;
      n->prev=NULL;
      (*j)--;
      printf("Excluido!\n");
      sleep(3);
      system("clear");
      hue->first=n;
      return(n);
    }
    else if(n != hue->first && n != hue->last){
      printf("eita\n");
      printf("cod = %d\n",n->info.codigo);
      n->next->prev=n->prev;
      n->prev->next=n->next;
      n=n->next;
      (*j)--;
      printf("Excluido!\n");
      sleep(3);
      system("clear");
      return(n);

    }
    else if(n == hue->last && n!= hue->first){
      n=n->prev;
      n->next=NULL;
      (*j)--;
      printf("Excluido!\n");
      sleep(3);
      system("clear");
      hue->last=n;
      return(n);
    }
  }
}

int main(){
  lista cabeca;
  cabeca.nItens=0;
  int *j;
  lista *hue;
  hue=&cabeca;
  j=&cabeca.nItens;
  nodo *n;
  int x;
  system("clear");
  do{
    printf("\t\tMENU\nInserir : 1\nExcluir : 2\nExibir : 3\nSair : 0\n");
    scanf("%d",&x);
    switch (x) {
      case 1:
        n=inserir(j,n,hue);
        break;
      case 2:
        n=excluir(j,n,hue);
        break;
      case 3:
        exibir(n,j);
        break;
      case 0:
        break;
      default:
        printf("Opção invalida\n");
        break;
    }

  }while(x != 0);
}
