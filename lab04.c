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
