#include <stdio.h>
#include <stdlib.h>
/*https://sites.google.com/site/proffdesiqueiraed/aulas/aula-6---listas-duplamente-encadeadas*/
/*https://wagnergaspar.com/como-construir-uma-lista-duplamente-encadeada/*/
struct elemento {
int info;
struct elemento *prox;
struct elemento *ant;
};

typedef struct elemento tipoElemento;

struct estruturaLDDE{
tipoElemento *primeiro;
tipoElemento *ultimo;
int tamanhoLista;
};

typedef struct estruturaLDDE tipoLDDE;

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereElementoFinal (tipoLDDE *listaAux)
{ // Alocando espaço para o elemento
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info);
  if (listaAux->tamanhoLista == 0){
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro=novo;
    listaAux->ultimo=novo;
  }else{
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo=novo; }
    listaAux->tamanhoLista++; 
}

int main(void) 
{
  tipoLDDE listaLDDE ; 
  tipoElemento lInfo ;
  for (int i = 0 ; i <= 9 ; i++)
  {
    insereElementoFinal(&listaLDDE) ;  
  }

 
  
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct elemento {
int info;
struct elemento *prox;
struct elemento *ant;
};

typedef struct elemento tipoElemento;

struct estruturaLDDE{
tipoElemento *primeiro;
tipoElemento *ultimo;
int tamanhoLista;
};

typedef struct estruturaLDDE tipoLDDE;

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereElementoFinal (tipoLDDE *listaAux)
{ // Alocando espaço para o elemento
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info);
  if (listaAux->tamanhoLista == 0){
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro=novo;
    listaAux->ultimo=novo;
  }else{
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo=novo; 
    }
    listaAux->tamanhoLista++; 
}

void insereJogada(tipoLDDE *listaAux)
{
  // Alocando espaço para o elemento
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info);
  if (listaAux->tamanhoLista == 0){
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro=novo;
    listaAux->ultimo=novo;
  }else{
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo=novo; 
    }
    listaAux->tamanhoLista++; 
}

void checaTripla(tipoLDDE *listaAux)
{
  
}

void listarLista(tipoLDDE *listaAux)
{
  
}

int main(void) 
{
  tipoLDDE listaLDDE ; 
  tipoElemento lInfo ;
  inicializaLista (&listaLDDE) ;
  for (int i = 0 ; i < 9 ; i++)
  {
    insereElementoFinal(&listaLDDE) ;  
  }
  for (int i = 0 ; i < 5 ; i++)
  {
    insereJogada(&listaLDDE) ;
    checaTripla(&listaLDDE) ;
    listarLista(&listaLDDE) ;
  }
 
  
  return 0;
  }


/*#include "ListaLinearED.h"

int listaVaziaLLED(ListaLinearED *lista){
  return lista->ultimo==0;
}

void inicializaListaLLED(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item){
  int i;
  printf("\nRa: %i",item.RA);
  printf("\nNome: %s",item.nome);
  for(i=0;i<3;i++){
    printf("\nNota %i: %.1f",i+1,item.notas[i]);
  }
  printf("\nFrequencia: %i\n",item.freq);
}


void imprimeListaLLED(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL){
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

int insereNoFinalLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int insereNoInicioLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    *item = ptrAux->item;
    lista->inicioLista = ptrAux->prox;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int buscaItemNaListaLLED(ListaLinearED *lista,int info,TipoItem *item,int *pos){
  TipoNoh *ptrAux;
  int cont=1;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux!=NULL){
      if(verificaIgualdade(ptrAux->item,info)){
        *item = ptrAux->item;
        *pos = cont;
        return 1;
      }
      cont++;
      ptrAux = ptrAux->prox;
    }
  }
  return 0;
}

int verificaIgualdade(TipoItem item,int info){
  if(item.RA==info)
    return 1;
  return 0;
}

int adicionaNaPosicao(ListaLinearED *lista,TipoItem item, int pos){
  TipoNoh *novoNoh, *ptrAux, *ptrAux2;
  if (!listaVaziaLLED(lista) && lista->ultimo>pos){
  novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  ptrAux = lista->inicioLista;
  for (int i = 0; i<pos; i++){  //para 'pos' iteracoes esse loop ira colocar o endereco do 'pos'esima item da lista na variavel ptrAux 
      ptrAux2 = ptrAux->prox;
      ptrAux = ptrAux2;
      }
    ptrAux2 = ptrAux->prox;
    ptrAux->prox = novoNoh;
    novoNoh->prox = ptrAux2;
  return 1;
  }
  else 
  return 0;
  }
int retiraDaPosicao(ListaLinearED *lista, int pos){
  TipoNoh *ptrAux, *ptrAux2;
  if(!listaVaziaLLED(lista) && lista->ultimo>pos){
    ptrAux = lista->inicioLista;
    for (int i = 0; i<pos; i++){ 
      ptrAux2 = ptrAux->prox;
      ptrAux = ptrAux2;
      }
    ptrAux2 = ptrAux->prox; 
    ptrAux->prox = ptrAux2->prox;
    return 1;
  }else
    return 0;
}
int retiraEspecifico(ListaLinearED *lista,int ra){
  TipoNoh *ptrAux, *ptrAux2, *ptrAux3,*ptrAux4;  //3  sao pra guardar os valores logo antes do loop while encontrar o ra correto
  if (!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while (ptrAux->item.RA != ra || ptrAux ==NULL ){
      ptrAux3 = ptrAux;
      ptrAux2 = ptrAux->prox;
      ptrAux = ptrAux2; 

    }
      if (ptrAux ==NULL) {
        return 0;
      }else{
        ptrAux3->prox = ptrAux->prox;
        return 1;
          }
  }else
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

struct elemento {
int info;
struct elemento *prox;
struct elemento *ant;
};

typedef struct elemento tipoElemento;

struct estruturaLDDE{
tipoElemento *primeiro;
tipoElemento *ultimo;
int tamanhoLista;
};

typedef struct estruturaLDDE tipoLDDE;

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereElementoFinal (tipoLDDE *listaAux)
{ // Alocando espaço para o elemento
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info);
  if (listaAux->tamanhoLista == 0){
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro=novo;
    listaAux->ultimo=novo;
  }else{
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo=novo; 
    }
    listaAux->tamanhoLista++; 
}

void insereJogada(tipoLDDE *listaAux)
{
  int posicao ;
  // Alocando espaço para o elemento
  tipoElemento *aux, *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info) ;
  scanf("%d", &posicao) ;
  if (posicao == 0){
    listaAux->primeiro->ant = novo ;
    novo->prox = NULL;
    novo->ant = NULL;
    listaAux->primeiro = novo;
    listaAux->ultimo = novo;
  }if (posicao == 9){ //inserindo no ultimo
    listaAux->ultimo->prox = novo ;
    novo->prox = NULL;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo = novo; 
  }else{
      int i = listaAux->tamanhoLista, aux = listaAux->primeiro->prox ;
      int count = 1 ;
      while (i > 0)
      {
        if (posicao == count){
          
          novo->prox = ;
          novo->ant = ;
          break ;
        }else
        
          count++ ;
          i-- ;
      }
    }
    listaAux->tamanhoLista++;
}

void checaTripla(tipoLDDE *listaAux)
{
  
}

int checaVencedor(tipoLDDE *listaAux)
{
  if (listaAux->tamanhoLista == 0)
  {
    printf("ganhou\n") ;
    return 1 ;
  }else return 0 ;
}

void listarLista(tipoLDDE *listaAux)
{
  
}

int main(void) 
{
  tipoLDDE listaLDDE ; 
  tipoElemento lInfo ;
  inicializaLista (&listaLDDE) ;
  for (int i = 0 ; i < 9 ; i++)
  {
    insereElementoFinal(&listaLDDE) ;  
  }
  for (int i = 0 ; i < 5 ; i++)
  {
    if (checaVencedor(&listaLDDE) == 0)
    {
      insereJogada(&listaLDDE) ;
      checaTripla(&listaLDDE) ;
      listarLista(&listaLDDE) ;
      checaVencedor(&listaLDDE) ;
    }else checaVencedor(&listaLDDE) ; break ;
  }
  
  return 0;
  }
