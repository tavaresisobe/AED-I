/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 25/10/2022 - 15:45h
*/

// ##################### Bibliotecas Externas ##############################
 
#include<stdio.h>
#include<stdlib.h> 
#define MAX 100

// ########################## TAD X.h ######################################

struct info
{
    int valor;
    int prox;
};
typedef struct info tipoInfo;

struct listaEE
{
    int tamanhoLista;
    int primeiro ;
    int ultimo ;
    int posLivre[MAX];
    tipoInfo elemento[MAX];
};
typedef struct listaEE tipoListaEE;

void inicializaLista (tipoListaEE *listaAux, int t)
{
    listaAux->tamanhoLista = 0 ;
    listaAux->primeiro = -1 ;
    listaAux->ultimo = -1;
    for (int i = 0 ; i < t ; i++)
    {
        listaAux->elemento[i].valor = 0 ;
        listaAux->elemento[i].prox = -1 ;
        listaAux-> posLivre[i] = 1 ; 
    }
}

void insereElementoOrdenado (tipoListaEE *listaAux, int posicao)
{
  int x ;
  scanf("%d", &x) ;
  if (posicao != -1 && x >= 60000 && x<= 140000)
  {
    listaAux->elemento[posicao].valor = x ;
    if (listaAux->tamanhoLista == 0) //caso seja o 1a
    {
      listaAux->primeiro = posicao ;
      listaAux->ultimo = posicao ;
      listaAux->elemento[posicao].prox = -1 ;
      listaAux->tamanhoLista++ ;
      listaAux->posLivre[posicao] = 0 ;
      printf("inseriu o primeiro elemento\n") ;
    }else if (listaAux->tamanhoLista > 0 && listaAux->elemento[posicao].valor > listaAux->elemento[listaAux->ultimo].valor){ //caso seja maior que o ultimo                 
      listaAux->elemento[listaAux->ultimo].prox = posicao ;
      listaAux->tamanhoLista++ ;
      listaAux->elemento[posicao].prox = -1 ;
      listaAux->posLivre[posicao] = 0 ;
      listaAux->ultimo = posicao ;
      printf ("Inseriu no ultimo\n") ;
    }else if (listaAux->tamanhoLista > 0 && listaAux->elemento[posicao].valor < listaAux->elemento[listaAux->primeiro].valor){  //caso seja menor que o primeiro
      listaAux->elemento[posicao].prox = listaAux->primeiro ;
      listaAux->tamanhoLista++ ;
      listaAux->posLivre[posicao] = 0 ;
      listaAux->primeiro = posicao ;
      printf ("Inseriu no primeiro\n") ;
    }else if (listaAux->tamanhoLista > 1){  //insercao intermediaria ordenada
      int aux ;
      for (int i = 0 ; i < listaAux->tamanhoLista ; i++)
      { 
        if (listaAux->elemento[posicao].valor > listaAux->elemento[i].valor)
        {
          aux = listaAux->elemento[i].prox ;
          if (listaAux->elemento[aux].valor > listaAux->elemento[posicao].valor)
          {
            listaAux->elemento[i].prox = posicao ;
            listaAux->elemento[posicao].prox = aux ;
            listaAux->tamanhoLista++ ;
            listaAux->posLivre[posicao] = 0 ;
            printf ("Inseriu entre dois elementos\n") ;
            break ;
          }
        }
      }
    }
  }else
      printf ("Nao existe\n") ;
}

void removerElemento (tipoListaEE *l)
{
    int x, i, tam, aux = l->primeiro ;
    scanf ("%d", &x) ;
    if (x >= 60000 && x <= 140000)
    {
        tam = l->tamanhoLista ; 
        while(tam > 0)
        {
          if (l->elemento[aux].valor == x){
            //remover elemento e atualizar encadeamento...
            break ;
          }else
            aux = l->elemento[aux].prox ;
            tam -- ;
        }
    }else
        printf("Nao existe\n") ;
}

int proxPosLivre(tipoListaEE *listaAux, int t)
{
    for (int i = 0 ; i < t ; i++)
    {
        if (listaAux->posLivre[i] == 1)
            return i ;
    }
    return -1;
}

//por ultimo:
void imprimeListaEE (tipoListaEE *l)
{
  int aux = l->primeiro, tam = l->tamanhoLista ;
  while (tam > 0)
  {
    printf ("%d ", l->elemento[aux].valor) ;
    aux = l->elemento[aux].prox ;
    tam -- ;
  }
  printf("\n") ;
}

// ###################### Funcoes e Procedimentos do programa ##############

void ano_de_ingresso(tipoListaEE *listaAux)
{
  //printar ano de ingresso e qtd.
}

// ############################ Principal ###################################

int main ()
{
  tipoInfo noListaEE ;
  tipoListaEE listaEE ;
  int t, i, aux, operacao ;
  scanf ("%d", &t) ;
  t = t * 2 ;
  if (t > 0)
  {
    inicializaLista(&listaEE, t) ;
    for (i = 0 ; i < t ; i++)
    {
      scanf("%d", &operacao) ;
      if (operacao == 1){
        aux = proxPosLivre(&listaEE, t) ;
        printf ("posLivre: %d\n" , aux) ;
        insereElementoOrdenado(&listaEE, aux) ;
        imprimeListaEE(&listaEE) ;
      }else if (operacao == 2){
        removerElemento(&listaEE) ;
      }
    }
    ano_de_ingresso(&listaEE) ;
  }else
    ano_de_ingresso(&listaEE) ;
    
    return 0 ;
}