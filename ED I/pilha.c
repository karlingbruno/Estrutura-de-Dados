#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50
typedef struct{
  int cod;
  char nome[TAM];
  float preco;
}produto;
typedef struct{
  produto *info;
  int topo;
}pilha;
void inserir(pilha *n){
    __fpurge(stdin);
    n->topo+=1;
    system("clear");
    printf("Digite o Codigo do produto:\n");
    scanf("%d",&(n->info+n->topo)->cod);
    printf("Digite o nome do produto:\n");
    getchar();
    fgets((n->info+n->topo)->nome,TAM,stdin);
    printf("Digite o preço do produto:\n");
    scanf("%f",&(n->info+n->topo)->preco);
    system("clear");
    printf("Produto cadastrado!\n");
    sleep(2.5);
    system("clear");
}
void excluir(pilha *n){
    n->topo--;
    system("clear");
    printf("Produto excluido!\n");
    sleep(2.5);
    system("clear");
}
void listar(pilha *n){
  int i,p;
  p=n->topo;
  system("clear");
  for(i=-1;i<p;i++){
    printf("Codigo do produto : %d\n",(n->info+n->topo)->cod);
    printf("Nome do produto : %s",(n->info+n->topo)->nome);
    printf("Preço do produto : %f\n\n",(n->info+n->topo)->preco);
  }
  sleep(4);
  system("clear");
}
int main(){
  int x,nprodutos;
  pilha *n;
  n->topo = -1;
  printf("Quantos produtos seram inseridos?\n");
  scanf("%d",&nprodutos);
  n = (pilha *)calloc(nprodutos,sizeof(produto));
  n->topo = -1;
  n->info = (produto *)calloc(nprodutos,sizeof(produto));
  system("clear");
  do{
    printf("\t\tMENU\nInserir um produto na pilha : 1\nExcluir um produto da pilha 2\nListar os campos da pilha : 3\nSAIR : 0\n");
    scanf("%d",&x);
    switch (x) {
      case 1:
        inserir(n);
        break;
      case 2:
        excluir(n);
        break;
      case 3:
        listar(n);
        break;
      case 0:
        break;
      default:
        printf("Opção Invalida\n");
        break;
    }
  }while(x != 0);

}
