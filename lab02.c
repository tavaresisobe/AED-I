/*http://www.sergioportari.com.br/wp-content/uploads/2018/11/aula06-Listas-encadeada.pdf
http://www.sergioportari.com.br/wp-content/uploads/2018/10/aula05-Listas-estaticas.pdf
https://www.sergioportari.com.br/aulas/2018-2/uemg-frutal/algoritmos-e-estruturas-de-dados-aed/
*/

/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 13/10/2022
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
            break ;
          }
        }
      }
    }
  }else
      printf ("Nao existe\n") ;
}

/*void removerElemento (tipoListaEE *listaAux, int t)
{
    int x, i, tam ;
    scanf ("%d", &x) ;
    if (x >= 60000 && x <= 140000)
    {
        tam = listaAux->tamanhoLista ; 
        while(tam > 0)
        {
            if ()
            
            
            tam -- ;
        }
    }else
        prinf ("Nao existe\n") ;
}*/

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
  int i = 0, aux = l->primeiro, tam = l->tamanhoLista ;
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
            //removerElemento(&listaEE, t) ;
      }
    }
    ano_de_ingresso(&listaEE) ;
  }else
    ano_de_ingresso(&listaEE) ;
    
    return 0 ;
}

/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 13/10/2022
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

void insereElementoFinal (tipoListaEE *listaAux, int posicao)
{ 
    if (posicao != -1)
    {
        scanf("%d", &listaAux->elemento[posicao].valor) ;
        if (listaAux->tamanhoLista == 0)  //atualizando dados do nó da lista
            listaAux->primeiro = posicao ;
        else listaAux->elemento[listaAux->ultimo].prox = posicao ;
        listaAux->elemento[posicao].prox = -1 ;
        listaAux->tamanhoLista++ ;
        listaAux->ultimo = posicao ;
        listaAux->posLivre[posicao] = 0 ;
        printf ("Deu certo\n") ;
    }
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
void imprimeLista (tipoListaEE *l)
{
  tipoListaEE *p ;
  int i = 0 ;
  for (p = l; p != NULL ; p = p->elemento[i].prox)
  {
    printf("info = %d\n", p->elemento[i].valor) ;
    i++ ;
  }
}

// ###################### Funcoes e Procedimentos do programa ##############

void ano_de_ingresso()
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
        insereElementoFinal(&listaEE, aux) ;
      }else if (operacao == 2){
            printf("Retirar\n") ;
      }
    }
  }else
    printf ("Nao\n") ;
    
    return 0 ;
}


/* Programa: Laboratório 2
   Autor: Gustavo Henrique Tavares Isobe
   Versao: 1.0 - 13/10/2022
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

void insereElementoFinal (tipoListaEE *listaAux, int posicao)
{ 
    if (posicao != -1)
    {
        int x ;
        scanf("%d", &x) ;
        if (x >= 60000 && x<= 140000)
        {
            if (listaAux->tamanhoLista == 0)  //atualizando dados do nó da lista
                listaAux->primeiro = posicao ;
            else listaAux->elemento[listaAux->ultimo].prox = posicao ;
            listaAux->elemento[posicao].prox = -1 ;
            listaAux->tamanhoLista++ ;
            listaAux->ultimo = posicao ;
            listaAux->posLivre[posicao] = 0 ;
            printf ("Deu certo\n") ;
        }else
            printf ("Nao existe\n") ;
    }
}

void removerElemento (tipoListaEE *listaAux, int t)
{
    int x, i, tam ;
    scanf ("%d", &x) ;
    if (x >= 60000 && x <= 140000)
    {
        tam = listaAux->tamanhoLista ; 
        while(tam > 0)
        {
            if ()
            
            
            tam -- ;
        }
    }else
        prinf ("Nao existe\n") ;
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
void imprimeLista (tipoListaEE *l)
{
  tipoListaEE *p ;
  int i = 0 ;
  for (p = l; p != NULL ; p = p->elemento[i].prox)
  {
    printf("info = %d\n", p->elemento[i].valor) ;
    i++ ;
  }
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
        insereElementoFinal(&listaEE, aux) ;
      }else if (operacao == 2){
            removerElemento(&listaEE, t) ;
      }
    }
    ano_de_ingresso(&listEE) ;
  }else
    ano_de_ingresso(&listEE) ;
    
    return 0 ;
}
