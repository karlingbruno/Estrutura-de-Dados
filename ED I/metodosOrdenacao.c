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
  nodo *u = (nodo *)calloc(1,sizeof(nodo));
  printf("Digite o código do produto :\n");
  scanf("%d",&u->info.codigo);
  getchar();
  printf("Digite o nome do produto :\n");
  fgets(u->info.nome,20,stdin);
  printf("Digite o preço do produto :\n");
  scanf("%f",&u->info.preco);
  (*j)++;
  if(*j == 1){
    u->next = u->prev = NULL;
    hue->first = hue->last = u;
  }else{
    u->next=NULL;
    u->prev=n;
    n->next=u;
    hue->last=u;
  }
  system("clear");
  printf("Produto cadastrado!\n");
  sleep(2);
  system("clear");
  return(u);

}
void exibir(lista *hue){
  system("clear");
  nodo *j = (nodo *)calloc(1,sizeof(nodo));
  if(hue->nItens == 0){
    printf("Lista vazia!\n");
    sleep(2);
    system("clear");
  }else{
    for(j = hue->first;j != NULL;j=j->next){
      printf("Código : %d\n",j->info.codigo);
      printf("Nome : %s",j->info.nome);
      printf("Preço : %.3f\n\n",j->info.preco);
    }
    sleep(2);
    system("clear");
  }
}
nodo *excluir(int *j,nodo *n,lista *hue){
  nodo *v = (nodo *)calloc(1,sizeof(nodo));
  v = hue->last;
  int x;
  system("clear");
  if( *j == 0){
    system("clear");
    printf("Lista Vazia!\n");
    sleep(2);
    n=NULL;
    return(n);
  }else{
    printf("Digite o código do produto para excluir:\n");
    scanf("%d",&x);
    for(;v->prev != NULL;v=v->prev){
      if(v->info.preco == x){
        break;
      }
    }
    if(v == hue->first && v == hue->last){
      hue->first = hue->last = NULL;
      v=NULL;
      (*j)--;
      printf("Excluido!\n");
      sleep(2);
      system("clear");
      for(;v->next != NULL; v = v->next){
      }
      return(v);
    }
    else if(v == hue->first && v != hue->last){
      v=v->next;
      v->prev=NULL;
      (*j)--;
      printf("Excluido!\n");
      sleep(2);
      system("clear");
      hue->first=v;
      for(;v->next != NULL; v = v->next){
      }
      return(v);
    }
    else if(v != hue->first && v != hue->last){
      v->next->prev=v->prev;
      v->prev->next=v->next;
      v=v->next;
      (*j)--;
      printf("Excluido!\n");
      sleep(2);
      system("clear");
      for(;v->next != NULL; v = v->next){
      }
      return(v);

    }
    else if(v == hue->last && v != hue->first){
      v=v->prev;
      v->next=NULL;
      (*j)--;
      printf("Excluido!\n");
      sleep(2);
      system("clear");
      hue->last=v;
      for(;v->next != NULL; v = v->next){
      }
      return(v);
    }
    else{
      printf("Código inválido!\n");
      return(v);
    }
  }
}
void insertion(lista *hue){
  system("clear");
  if(hue->nItens == 0){
    printf("Lista Vazia!\n");
    sleep(2);
    return;
  }
  nodo *i = (nodo *)calloc(1,sizeof(nodo));
  nodo *atual = (nodo *)calloc(1,sizeof(nodo));
  nodo *ant = (nodo *)calloc(1,sizeof(nodo));
  for(i=hue->first->next ; i != NULL; i=i->next){
    for(ant = i->prev, atual = i; ant != NULL; ant = ant->prev){
      if(atual->info.codigo < ant->info.codigo){
        if(hue->nItens == 2){
          hue->first = atual;
          ant->prev = atual;
          hue->last = ant;
          atual->next = ant;
          atual->prev = NULL;
          ant->next = NULL;
        }
        else if(ant == hue->first){
          hue->first = atual;
          ant->prev = atual;
					atual->next->prev = ant;
					ant->next = atual->next;
					atual->next = ant;
					atual->prev = NULL;
        }
        else if(atual == hue->last){
					hue->last = ant;
          atual->next = ant;
					ant->prev->next = atual;
					atual->prev = ant->prev;
					atual->next = ant;
					ant->next = NULL;
				}
				else{
					atual->next->prev = ant;
					ant->prev->next = atual;
					ant->next = atual->next;
					atual->prev = ant->prev;
					atual->next = ant;
					ant->prev = atual;
      }
    }
  }
}
          system("clear");
          printf("Ordenado!\n");
          sleep(2);
          system("clear");
}
void selection(lista *hue){
  system("clear");
  if(hue->nItens == 0){
    printf("Lista Vazia!\n");
    sleep(2);
    return;
  }
  nodo *menor,*i,*j,*primeiro,*aux,*aux2;
  for(i = hue->first; i != NULL; i = i->next){
    menor = i;
    primeiro = i;
    for(j = i;j != NULL; j = j->next){
      if(j->info.codigo < menor->info.codigo){
        menor = j;
      }
    }
    if(menor == primeiro){
      continue;
    }
    else if(primeiro == hue->first && menor == hue->last){//troca o primeiro e o ultimo da cabeça de lista
      hue->first = menor;
      primeiro->next->prev = menor;
			hue->last =primeiro;
      menor->prev->next = primeiro;
			menor->next = primeiro->next;
			primeiro->prev = menor->prev;
			primeiro->next = NULL;
      menor->prev = NULL;
    }
    else if((primeiro == hue->first) && (menor == hue->first->next)){//troca o primeiro e o segundo da cabeça de lista
			hue->first = menor;
      primeiro->prev = menor;
			primeiro->next = menor->next;
			menor->next = primeiro;
      primeiro->next->prev = primeiro;
			menor->prev = NULL;
    }
    else if((menor == hue->last) && (primeiro == hue->last->prev)){//troca o ultimo e o penultimo da cabeça de lista
			hue->last = primeiro;
      menor->next = primeiro;
			menor->prev = primeiro->prev;
			primeiro->prev = menor;
      primeiro->prev->next = menor;
			primeiro->next = NULL;
		}
    else if(primeiro == hue->first){//troca o primeiro com qualquer outro do meio a partir do segundo
			aux = menor->prev;
			aux2 = menor->next;
			hue->first =menor;
      primeiro->next->prev = menor;
			menor->next = primeiro->next;
			primeiro->prev = aux;
			primeiro->next = aux2;
			aux->next =primeiro;
      primeiro->prev = primeiro;
			menor->prev = NULL;
    }
    else if(menor == primeiro->next){//troca o segundo da lista não ordenada
			menor->next->prev = primeiro;
			primeiro->prev->next = menor;
			primeiro->next = menor->next;
			menor->prev = primeiro->prev;
			menor->next = primeiro;
			primeiro->prev = menor;
		}
    else{//troca qualquer um do meio da lista não ordenada
			aux = menor->prev;
			aux2 = menor->next;
			menor->next = primeiro->next;
			menor->prev = primeiro->prev;
			menor->next->prev =menor;
      menor->prev->next = menor;
			primeiro->next = aux2;
			primeiro->prev = aux;
			aux->next = primeiro;
      aux2->prev = primeiro;
		}
      i = menor;
    }
    system("clear");
    printf("Ordenado!\n");
    sleep(2);
    system("clear");
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
    printf("\t\tMENU\n1 : Inserir\n2 : Excluir\n3 : Exibir\n4 : Insertion\n5 : Selection\n0 : Sair\n");
    scanf("%d",&x);
    switch (x) {
      case 1:
        n=inserir(j,n,hue);
        break;
      case 2:
        n=excluir(j,n,hue);
        break;
      case 3:
        exibir(hue);
        break;
      case 4:
        insertion(hue);
        break;
      case 5:
        selection(hue);
        break;
      default:
        printf("Opção invalida\n");
        break;
    }

  }while(x != 0);
}
