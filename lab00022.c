/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 27/10/2022 - 20:54h
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

void insereElementoOrdenado (tipoListaEE *l, int posicao, int *limite)
{
  int x ;
  scanf("%d", &x) ;
  if (posicao != -1 && x >= 60000 && x<= 140000)
  {
    l->elemento[posicao].valor = x ;
    if (*limite < 10)
    {
      if (l->tamanhoLista == 0) //caso seja o 1a
      {
        l->primeiro = posicao ;  //atualizando encadeamento
        l->ultimo = posicao ;
        l->elemento[posicao].prox = -1 ;
        l->tamanhoLista++ ;
        l->posLivre[posicao] = 0 ;
        *limite += 1 ;
      }else if (l->elemento[posicao].valor > l->elemento[l->ultimo].valor)
      {     
        l->elemento[l->ultimo].prox = posicao ;
        l->tamanhoLista++ ;
        l->elemento[posicao].prox = -1 ;
        l->posLivre[posicao] = 0 ;
        l->ultimo = posicao ;
        *limite += 1 ;
      }else if (l->elemento[posicao].valor < l->elemento[l->primeiro].valor)  //caso seja menor que o primeiro
      {
        l->elemento[posicao].prox = l->primeiro ;
        l->tamanhoLista++ ;
        l->posLivre[posicao] = 0 ;
        l->primeiro = posicao ;
        *limite += 1 ;
      }else  //insercao intermediaria ordenada
      {
        int i = 0 ;
        int back = l->primeiro ;
        int next = l->elemento[l->primeiro].prox ;
        while (i < l->tamanhoLista)
        {
          if (l->elemento[posicao].valor < l->elemento[next].valor)
          {
            l->elemento[back].prox = posicao ;  //atualiza encadeamento
            l->elemento[posicao].prox = next ;
            l->tamanhoLista++ ;
            l->posLivre[posicao] = 0 ;
            *limite += 1 ;
            break ;
          }else
            back = next ;
            next = l->elemento[next].prox ;
            i ++ ;
        }
      }
    }else
      printf ("lista cheia\n") ;
  }else
      printf ("nao existe\n") ;
}

void removerElemento (tipoListaEE *l, int *limite)
{
    int i = 0, x, achou = 0 ;
    scanf ("%d", &x) ;
    if (x >= 60000 && x <= 140000)
    {
      if (x == l->elemento[l->primeiro].valor) //removendo 1o elemento
      {
        int g = l->elemento[l->primeiro].prox  ;
        l->posLivre[l->primeiro] = 1 ;
        l->elemento[l->primeiro].valor = 0 ;
        l->elemento[l->primeiro].prox = -1 ;
        l->tamanhoLista -- ;
        l->primeiro = g ;
        *limite -= 1 ;
        achou = 1 ;
      }else
        if (x == l->elemento[l->ultimo].valor) //removendo ultimo
        {
          int ant = l->primeiro, suc = l->elemento[l->primeiro].prox ;
          for (int j = 0 ; j < l->tamanhoLista ; j++)  //buscando penultimo elemento da lista
          {
            if (l->elemento[suc].prox == l->ultimo){
              l->posLivre[l->ultimo] = 1 ;
              l->elemento[l->ultimo].valor = 0 ;
              l->elemento[l->ultimo].prox = -1 ;
              l->tamanhoLista -- ;
              l->ultimo = ant ;
              l->elemento[l->ultimo].prox = -1 ;
              *limite -= 1 ;
              achou = 1 ;
              break ;
            }else
              ant = suc ;
              suc = l->elemento[suc].prox ;
            }
        }else
        {
          int back = l->primeiro ;
          int next = l->elemento[l->primeiro].prox ;
          while(i < l->tamanhoLista) //removendo elemento intermediario da lista
          {
            if (x == l->elemento[next].valor)
            {
              l->elemento[back].prox = l->elemento[next].prox ;
              l->elemento[next].valor = 0 ;
              l->elemento[next].prox = -1 ;
              l->posLivre[next] = 1 ;
              l->tamanhoLista -- ;
              *limite -= 1 ;
              achou = 1 ;
              break ;
            }else
              back = next ;
              next = l->elemento[next].prox ;
              i ++ ;
          }
        }
    }
    if (achou == 0)
    {
      printf("nao existe\n") ;
    }
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
  int i = 0, j = l->primeiro ;
  int y2011 = 0, y2012 = 0, y2013 = 0, y2014 = 0, y2015 = 0, y2016 = 0, y2017 = 0, y2018 = 0 ;
  while (i < l->tamanhoLista)
  {
    if (l->elemento[j].valor >= 60000 && l->elemento[j].valor < 70000)
    {
      y2011 ++ ;
    }else
    if (l->elemento[j].valor >= 70000 && l->elemento[j].valor < 80000)
    {
      y2012 ++ ;
    }else
    if (l->elemento[j].valor >= 80000 && l->elemento[j].valor < 90000)
    {
      y2013 ++ ;
    }else
    if (l->elemento[j].valor >= 90000 && l->elemento[j].valor < 100000)
    {
      y2014 ++ ;
    }else
    if (l->elemento[j].valor >= 100000 && l->elemento[j].valor < 110000)
    {
      y2015 ++ ;
    }else
    if (l->elemento[j].valor >= 110000 && l->elemento[j].valor < 120000)
    {
      y2016 ++ ;
    }else
    if (l->elemento[j].valor >= 120000 && l->elemento[j].valor < 130000)
    {
      y2017 ++ ;
    }else
    if (l->elemento[j].valor >= 130000 && l->elemento[j].valor < 140000)
    {
      y2018 ++ ;
    }
    j = l->elemento[j].prox ;
  }
  printf ("2011: %d\n2012: %d\n2013: %d\n2014: %d\n2015: %d\n2016: %d\n2017: %d\n2018: %d\n", y2011, y2012, y2013, y2014, y2015, y2016, y2017, y2018) ;
}

// ############################ Principal ###################################

int main ()
{
  tipoInfo noListaEE ;
  tipoListaEE listaEE ;
  int t, i, aux, operacao, limite = 0 ;
  scanf ("%d", &t) ;
  if (t > 0)
  {
    inicializaLista(&listaEE, t) ;
    for (i = 0 ; i < t ; i++)
    {
      scanf("%d", &operacao) ;
      if (operacao == 1){
        aux = proxPosLivre(&listaEE, t) ;
        insereElementoOrdenado(&listaEE, aux, &limite) ;
        imprimeListaEE(&listaEE) ;
      }else if (operacao == 2){
        removerElemento(&listaEE, &limite) ;
        imprimeListaEE(&listaEE) ;
      }
    }
    ano_de_ingresso(&listaEE) ;
  }else
    ano_de_ingresso(&listaEE) ;
    
    return 0 ;
}
