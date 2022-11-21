/* Programa: lab 5
   Autor: Gustavo Henrique Tavares Isobe -  RA: 158552 
   Versao: 2.0 - 20/11/2022 - 21:38 h
*/

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 100

// ########################## TAD X.h ######################################

struct filaCircular {
    int primeiro;
    int ultimo;
    int tamanhofila;
    int elementos[tamanhoMAX];
};
typedef struct filaCircular tipoFC;

void inicializaFila (tipoFC *filaAux)
{
    int i ;
    filaAux->primeiro = -1;
    filaAux->ultimo = -1;
    for (i = 0 ; i < tamanhoMAX ; i++)
    {
        filaAux->elementos[i] = 0;
    }
}

int filaVazia(tipoFC *filaAux){
    if ((filaAux->primeiro==filaAux->ultimo) && (filaAux->ultimo==-1))
        return 1;
    else return 0; 
}

int filaCheia (tipoFC *filaAux){
    if (((filaAux->ultimo + 1) % tamanhoMAX) == filaAux->primeiro)
        return 1;
    else return 0;
}  

void insereTarefa (tipoFC *filaAux, int info)
{ 
    if (filaVazia(filaAux) == 1)
    { filaAux->primeiro = 0 ;
      filaAux->ultimo = 0 ;
      filaAux->elementos[0] = info ;
      filaAux->tamanhofila ++ ;
    }else if (filaCheia(filaAux) == 0){
        int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
        filaAux->elementos[posicao] = info;
        filaAux->ultimo = posicao;
        filaAux->tamanhofila ++ ;
    }
}

// ###################### Funcoes e Procedimentos do programa ##############

void removerTarefa (tipoFC *filaAux)
{
    if (filaVazia(filaAux) == 0)
    {
        filaAux->elementos[filaAux->primeiro] = 0 ;
        filaAux->tamanhofila -- ;
        if (filaAux->tamanhofila == 0)
        {
            filaAux->primeiro = -1 ;
            filaAux->ultimo = -1 ;
        }else
            filaAux->primeiro + 1 ;
    }else
        printf ("vazia\n") ;
}

void finalizarTarefa (tipoFC *filaAux)
{
    int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    if (filaVazia(filaAux) == 0)
    {
        if (filaAux->tamanhofila > 1)
        {
            filaAux->elementos[posicao] = filaAux->elementos[filaAux->primeiro] ;
            filaAux->elementos[filaAux->primeiro] = 0 ;
            filaAux->primeiro = filaAux->primeiro + 1 ;
            filaAux->ultimo = posicao ;
        }
    }else
        printf ("vazia\n") ;
}

void listarFila(tipoFC *filaAux) {
  int i = filaAux->ultimo ;
  for (int j = 0 ; j < filaAux->tamanhofila ; j++)
  {
    printf ("%d ", filaAux->elementos[i]) ;
    i-- ;
  }
  printf ("\n") ;
}

// ############################ Principal ###################################

int main ()
{
    tipoFC filaEsC ;
    int i, x, op, valor ;
    scanf ("%d", &x) ;
    if (x > 0 && x <= 100)
    {
        inicializaFila(&filaEsC) ;
        for (i = 0 ; i < x ; i++)
        {
            scanf ("%d", &op) ;
            if (op == 1)
            {
                scanf ("%d", &valor) ;
                insereTarefa(&filaEsC, valor) ;
            }
            if (op == 2)
            {
                removerTarefa(&filaEsC) ;
            }
            if (op == 3)
            {
                finalizarTarefa(&filaEsC) ;
            }
        }
    }
    listarFila(&filaEsC) ;
    return 0 ;
}
