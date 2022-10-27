/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 25/10/2022 - 15:53h
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

void inicializaLista (tipoListaEE *l, int t)
{
    l->tamanhoLista = 0 ;
    l->primeiro = -1 ;
    l->ultimo = -1;
    for (int i = 0 ; i < t ; i++)
    {
        l->elemento[i].valor = 0 ;
        l->elemento[i].prox = -1 ;
        l-> posLivre[i] = 1 ; 
    }
}

void insereElementoOrdenado (tipoListaEE *l, int posicao)
{
  int x ;
  scanf("%d", &x) ;
  if (posicao != -1 && x >= 60000 && x<= 140000)
  {
    l->elemento[posicao].valor = x ;
    if (l->tamanhoLista == 0) //caso seja o 1a
    {
      l->primeiro = posicao ;
      l->ultimo = posicao ;
      l->elemento[posicao].prox = -1 ;
      l->tamanhoLista++ ;
      l->posLivre[posicao] = 0 ;
      printf("inseriu o primeiro elemento\n") ;
    }else if (l->tamanhoLista > 0 && l->elemento[posicao].valor > l->elemento[l->ultimo].valor){ //caso seja maior que o ultimo                 
      l->elemento[l->ultimo].prox = posicao ;
      l->tamanhoLista++ ;
      l->elemento[posicao].prox = -1 ;
      l->posLivre[posicao] = 0 ;
      l->ultimo = posicao ;
      printf ("Inseriu no ultimo\n") ;
      
    }else if (l->tamanhoLista > 0 && l->elemento[posicao].valor < l->elemento[l->primeiro].valor){  //caso seja menor que o primeiro
      
      l->elemento[posicao].prox = l->primeiro ;
      l->tamanhoLista++ ;
      l->posLivre[posicao] = 0 ;
      l->primeiro = posicao ;
      printf ("Inseriu no primeiro\n") ;
      
    }else if (l->tamanhoLista > 1 && l->elemento[posicao].valor > l->elemento[l->primeiro].valor && l->elemento[posicao].valor < l->elemento[l->ultimo].valor){  //insercao intermediaria ordenada
      int i = 0 ;
      int back = l->primeiro ;
      int next = l->elemento[l->primeiro].prox ;
      while (i < l->tamanhoLista)
      {
        if (l->elemento[posicao].valor < l->elemento[next].valor)
        {
          l->elemento[back].prox = posicao ;
          l->elemento[posicao].prox = next ;
          l->tamanhoLista++ ;
          l->posLivre[posicao] = 0 ;
          printf ("Inseriu no meio\n") ;
          break ;
        }else
          back = next ;
          next = l->elemento[next].prox ;
          i ++ ;
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

int proxPosLivre(tipoListaEE *l, int t)
{
    for (int i = 0 ; i < t ; i++)
    {
        if (l->posLivre[i] == 1)
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

void ano_de_ingresso(tipoListaEE *l)
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
