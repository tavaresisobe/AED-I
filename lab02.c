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
    int primeiro;
    int ultimo;
    int posLivre[MAX];
    tipoInfo elemento[MAX];
};
typedef struct listaEE tipoListaEE;

void inicializaLista (tipoListaEE *listaAux)
{
    listaAux->tamanhoLista = 0 ;
    listaAux->primeiro = -1 ;
    listaAux->ultimo = -1;
    for (i = 0 ; i < N ; i++)
    {
        listaAux->elemento[MAX].valor = 0 ;
        listaAux->elemento[MAX].prox = -1 ;
        listaAux-> posLivre[MAX] = 1 ; 
    }
}

void insereElementoFinal (tipoListaEE *listaAux, int posicao)
{ 
    if (posicao!=-1)
    {
        scanf("%d", &listaAux->elemento[posicao].valor) ;
        if (listaAux->tamanhoLista == 0) 
            listaAux->primeiro=posicao ;
        else
            listaAux->elemento[listaAux->ultimo].prox = posicao;
            listaAux->elemento[posicao].prox=-1;
            listaAux->tamanhoLista++;
            listaAux->ultimo=posicao;
            listaAux->posLivre[posicao] = 0 ; 
    }
}

int proxPosLivre(tipoListaEE *listaAux)
{
    for (i=0;i<N;i++)
    {
        if (listaAux->posLivre[i]==1)
            return i;
    }
    return -1;
}
// ###################### Funcoes e Procedimentos do programa ##############

 

// ############################ Principal ###################################

int main ()
{
    int 
    
    
    
    return 0 ;
}

/*
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
    int primeiro;
    int ultimo;
    int posLivre[MAX];
    tipoInfo elemento[MAX];
};
typedef struct listaEE tipoListaEE;

void inicializaLista (tipoListaEE *listaAux)
{
    listaAux->tamanhoLista = 0 ;
    listaAux->primeiro = -1 ;
    listaAux->ultimo = -1;
    for (i = 0 ; i < N ; i++)
    {
        listaAux->elemento[MAX].valor = 0 ;
        listaAux->elemento[MAX].prox = -1 ;
        listaAux-> posLivre[MAX] = 1 ; 
    }
}

void insereElementoFinal (tipoListaEE *listaAux, int posicao)
{ 
    if (posicao!=-1)
    {
        scanf("%d", &listaAux->elemento[posicao].valor) ;
        if (listaAux->tamanhoLista == 0) 
            listaAux->primeiro=posicao ;
        else
            listaAux->elemento[listaAux->ultimo].prox = posicao;
            listaAux->elemento[posicao].prox=-1;
            listaAux->tamanhoLista++;
            listaAux->ultimo=posicao;
            listaAux->posLivre[posicao] = 0 ; 
    }
}

int proxPosLivre(tipoListaEE *listaAux)
{
    for (i=0;i<N;i++)
    {
        if (listaAux->posLivre[i]==1)
            return i;
    }
    return -1;
}
// ###################### Funcoes e Procedimentos do programa ##############

void listacheia()
{
    
}

void remocao()
{
    
}

// ############################ Principal ###################################

int main ()
{
    int 
    
    
    
    return 0 ;
}*/
   
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
        if (listaAux->tamanhoLista == 0) 
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
// ###################### Funcoes e Procedimentos do programa ##############

void ano_de_ingresso()
{
  //printar qtd dos ra's e ano de ingresso.
}

// ############################ Principal ###################################

int main ()
{
  tipoInfo noListaEE ;
  tipoListaEE listaEE ;
  int t, i, aux ;
  scanf ("%d", &t) ;
  t = t * 2 ;
  if (t > 0)
  {
    inicializaLista(&listaEE, t) ;
    for (i = 0 ; i < t ; i++)
    { 
      aux = proxPosLivre(&listaEE, t) ;
      insereElementoFinal(&listaEE, aux) ;
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
