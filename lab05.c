#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 100
//1: inserir elemento
//2: remover ultimo elemento
//3: mudar o primeiro elemento para o final
struct filaCircular{
  int primeiro;
  int ultimo;
  int tamanhofila;
  int elementos[tamanhoMAX];
};
typedef struct filaCircular tipoFC;

void inicializaFila(tipoFC *filaAux) {
  // inicializa a fila
  int i;
  filaAux->primeiro = -1;
  filaAux->ultimo = -1;
  for (i = 0; i < tamanhoMAX; i++)
    filaAux->elementos[i] = 0;
}

void insereElemento(tipoFC *filaAux,int info) { // se a fila estiver vazia insere o primeiro elemento
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0 ;
    filaAux->ultimo = 0 ;
    filaAux->elementos[0] = info ;
  }else if (filaCheia(filaAux) == 0) { // se a fila não estiver cheia podemos inserir
    int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = info ;
    filaAux->ultimo = posicao ;
  }else
    printf("overflow: fila cheia") ;
}

int filaVazia(tipoFC *filaAux) {
  if ((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1))
    return 1 ; // fila está vazia
  else
    return 0 ; // fila não está vazia
}

int filaCheia(tipoFC *filaAux) {
  if (((filaAux->ultimo + 1) % tamanhoMAX) == filaAux->primeiro)
    return 1 ; // fila está cheia
  else
    return 0 ; // fila não está cheia
}

int main(void) {
  tipoFC filaEsC ;
  int i, x, op = 0, num ;
  scanf("%d", &x) ;
  if (x > 0) 
  {
    inicializaFila(&filaEsC) ;
    for (i = 0; i < x; i++)
    {
      scanf("%d", &op) ;
      if (op == 1) 
      {
        scanf ("%d", &num) ;
        insereElemento(&filaEsC, num) ;
      }if (op == 2)
      {
        printf ("Vai Corinthians\n");
      }if (op == 3)
      {
        printf ("Palmeiras não tem mundial\n");
      }
    }
  }
  return 0;
}
