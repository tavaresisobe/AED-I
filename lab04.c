/* Programa: lab 4
   Autor: Gustavo Henrique Tavares Isobe -  RA: 158552 
   Versao: 2.0 - 11/12/2022 - 13:48 h
*/

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

struct elemento {
  int info ;
  struct elemento *prox ;
  struct elemento *ant ;
};
typedef struct elemento tipoElemento ;

struct estruturaLDDE{
  tipoElemento *primeiro ;
  tipoElemento *ultimo ;
  int tamanhoLista ;
};
typedef struct estruturaLDDE tipoLDDE ;

// ###################### Funcoes e Procedimentos do programa ##############

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL ;
  listaAux->tamanhoLista = 0 ;
}

void insereElementoFinal (tipoLDDE *listaAux)
{ // Alocando espaço para o elemento
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  // fazendo leitura dos dados para info
  scanf("%d", &novo->info) ;
  if (listaAux->tamanhoLista == 0)
  {
    novo->prox = NULL ;
    novo->ant = NULL ;
    listaAux->primeiro = novo ;
    listaAux->ultimo = novo ;
    listaAux->tamanhoLista++; 
  }else{
      novo->prox = NULL;
      novo->ant = listaAux->ultimo;
      listaAux->ultimo->prox = novo;
      listaAux->ultimo=novo; 
      listaAux->tamanhoLista++; 
  }
}

void insereJogada(tipoLDDE *listaAux)
{
  int posicao ;
  tipoElemento *a, *b, *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
  scanf("%d", &novo->info) ;
  scanf ("%d", &posicao) ;
  if (novo->info >= 1 && novo->info <= 9)
  {
    if (posicao == 0)
    {
      novo->prox = listaAux->primeiro ;
      novo->ant = NULL ;
      listaAux->primeiro->ant = novo ;
      listaAux->primeiro = novo ;
      listaAux->tamanhoLista++ ;
    }else
      if (posicao == listaAux->tamanhoLista - 1)
      {
        novo->prox = NULL ;
        novo->ant = listaAux->ultimo ;
        listaAux->ultimo->prox = novo ;
        listaAux->ultimo = novo ;
        listaAux->tamanhoLista++ ;
      }else 
          if (posicao > 0 && posicao < listaAux->tamanhoLista)
          {
            int aux = 1 ;
            b = listaAux->primeiro->prox ;
            a = b->ant ;
            while(aux <= listaAux->tamanhoLista - 1)
            {
               if (aux == posicao)
               {
                  novo->prox = b ;
                  novo->ant = a ;
                  a->prox = novo ;
                  b->ant = novo ;
                  listaAux->tamanhoLista ++ ;
                  break ;
                }else
                  a = b ;
                  b = b->prox ;
                  aux ++ ;
            }
          }
  }else free (novo) ;
}



void listarLista(tipoLDDE *listaAux)
{
  printf ("\n") ;
  tipoElemento *p ;
  p = listaAux->primeiro ;
  while (p)
  {
    printf ("%d ", p->info) ;
    p = p->prox ;
  }
}

// ############################ Principal ###################################

int main ()
{
  tipoElemento elementoS ;
  tipoLDDE listaDDE ;
  inicializaLista(&listaDDE) ;

  int i ;
  for (i = 0 ; i < 10 ; i++)
  {
    insereElementoFinal(&listaDDE) ;
     listarLista(&listaDDE) ;
  }
  printf ("\nInserindo jogada:") ;
  for (i = 0 ; i < 5 ; i++)
  {
    insereJogada(&listaDDE) ;
    listarLista(&listaDDE) ;
  }
  
  return 0 ;
}

//1 3 2 8 7 6 4 9 5 3 4 0 3 0 8 0 9 0 1 9
