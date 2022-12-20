/* Programa: lab 4
   Autor: Gustavo Henrique Tavares Isobe -  RA: 158552 
   Versao: 3.0 - 20/12/2022 - 20:02 h
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

void inicializaLista (tipoLDDE *listaAux)
{
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL ;
  listaAux->tamanhoLista = 0 ;
}

void insereElementoFinal (tipoLDDE *listaAux)
{
  tipoElemento *novo = (tipoElemento*) malloc(sizeof(tipoElemento));
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

// ###################### Funcoes e Procedimentos do programa ##############

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
    if (posicao == listaAux->tamanhoLista)
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

void verificaInicioFim(tipoLDDE *listaAux)
{
    tipoElemento *a = listaAux->primeiro, *b = a->prox, 
    *c = listaAux->ultimo, *p, *u ;
    if (a->info + b->info + c->info == 10)
    {
        if (listaAux->tamanhoLista == 4)
        {
            p = c->ant ;
            p->prox = NULL ;
            p->ant = NULL ;
            listaAux->primeiro = p ;
            listaAux->ultimo = p ;
            free(a) ;
            free(b) ;
            free(c) ;
        }else
            p = b->prox ;
            p->ant = NULL ;
            listaAux->primeiro = p ;
            u = c->ant ;
            u->prox = NULL ;
            listaAux->ultimo = u ;
            listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
            free(a) ;
            free(b) ;
            free(c) ;
    }
}
void verificaFimInicio(tipoLDDE *listaAux)
{
    tipoElemento *a = listaAux->primeiro, *b = listaAux->ultimo, 
    *c = b->ant, *p, *u ;
    if (a->info + b->info + c->info == 10)
    {
        if (listaAux->tamanhoLista == 4)
        {
            p = a->prox ;
            p->prox = NULL ;
            p->ant = NULL ;
            listaAux->primeiro = p ;
            listaAux->ultimo = p ;
            listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
            free(a) ;
            free(b) ;
            free(c) ;
        }else
            p = a->prox ;
            p->ant = NULL ;
            listaAux->primeiro = p ;
            u = c->ant ;
            u->prox = NULL ;
            listaAux->ultimo = u ;
            listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
            free(a) ;
            free(b) ;
            free(c) ;
    }
}

void verificaTripla(tipoLDDE *listaAux)
{
  tipoElemento *a, *b, *c, *aux, *aux_2 ;
  a = listaAux->primeiro ;
  b = a->prox ;
  c = b->prox ;
  if (listaAux->tamanhoLista >= 3)
  {
    while(c){
      if (a->info + b->info + c->info == 10)
      {
        if (listaAux->primeiro == a)
        {
           aux = c->prox ;
           listaAux->primeiro = aux ;
           aux->ant = NULL ;
           free(a);
           free(b);
           free(c);
           listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
           break ;
        }else
        if (listaAux->ultimo == c)
        {
           aux = a->ant ;
           listaAux->ultimo = aux ;
           aux->prox = NULL ;
           free(a);
           free(b);
           free(c);
           listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
           break ;
        }else
        if (c->prox != NULL)
        {
           aux = a->ant ;
           aux_2 = c->prox ;
           aux->prox = aux_2 ;
           aux_2->ant = aux ;
           free(a);
           free(b);
           free(c);
           listaAux->tamanhoLista = listaAux->tamanhoLista - 3 ;
           break ;
        }
      }else
        a = b ;
        b = c ;
        c = c->prox ;
    }
  }
}

int check_vencedor(tipoLDDE *listaAux)
{
    tipoElemento *a = listaAux->primeiro, *b = a->prox , *c = b->prox ;
    if (a->info + b->info + c->info == 10)
    {
        listaAux->primeiro = NULL;
        listaAux->ultimo = NULL ;
        listaAux->tamanhoLista = 0 ;
        free(a);
        free(b);
        free(c);
    }
}

void ganhou(tipoLDDE *listaAux)
{
    if (listaAux->tamanhoLista == 0)
        printf ("ganhou\n") ;
    else
        printf ("perdeu\n") ;
}

void listarLista(tipoLDDE *listaAux)
{
  tipoElemento *p ;
  if (listaAux->primeiro > 0)
  {
    p = listaAux->primeiro ;
    while (p)
    {
        printf ("%d ", p->info) ;
        p = p->prox ;
    }printf ("\n") ;
  }
}

// ############################ Principal ###################################

int main ()
{
  tipoElemento elementoS ;
  tipoLDDE listaDDE ;
  inicializaLista(&listaDDE) ;

  int i;
  for (i = 0 ; i < 10 ; i++)
  {
    insereElementoFinal(&listaDDE) ;
  }
  listarLista(&listaDDE) ;
  for (i = 0 ; i < 5 && listaDDE.tamanhoLista > 0 ; i++)
  {
    insereJogada(&listaDDE) ;
    if (listaDDE.tamanhoLista > 3)
    {
        verificaTripla(&listaDDE) ;
    if (listaDDE.tamanhoLista > 3)
    {
        verificaFimInicio(&listaDDE) ;
    }if (listaDDE.tamanhoLista > 3)
    {
        verificaInicioFim(&listaDDE) ;
    }
    if (listaDDE.tamanhoLista > 3)
    {
        verificaTripla(&listaDDE) ;
        verificaFimInicio(&listaDDE) ;
        verificaInicioFim(&listaDDE) ;
    }
    }if (listaDDE.tamanhoLista == 3)
    {
        check_vencedor (&listaDDE) ;
    }
    listarLista(&listaDDE) ;
  }
  ganhou(&listaDDE) ;
  return 0 ;
}
// 1 6 4 3 2 7 0 5 3 9 2 8 1 0 1 0 4 0 2 0
