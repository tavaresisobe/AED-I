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
