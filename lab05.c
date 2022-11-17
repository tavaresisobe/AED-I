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
  filaAux->tamanhofila = 0 ;
  for (i = 0; i < tamanhoMAX; i++)
    filaAux->elementos[i] = 0;
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

void insereTarefa(tipoFC *filaAux,int info) { // se a fila estiver vazia insere o primeiro elemento
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0 ;
    filaAux->ultimo = 0 ;
    filaAux->elementos[0] = info ;
    filaAux->tamanhofila++;
  }else if (filaCheia(filaAux) == 0) { // se a fila não estiver cheia podemos inserir
    int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = info ;
    filaAux->ultimo = posicao ;
    filaAux->tamanhofila++ ;
  }else
    printf("cheia") ; 
}

void removeTarefa (tipoFC *filaAux)
{
  if (filaCheia(filaAux) == 0)
  {
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro + 1 ;
    filaAux->tamanhofila --;
  }else
    printf ("vazia\n") ;
}

void finalizarTarefa(tipoFC *filaAux)
{
  if (filaVazia(filaAux) == 0)
  {
    int posicao = posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = filaAux->elementos[filaAux->primeiro] ;
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro+1 ;
    filaAux->ultimo = posicao ;
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
}

/*void listarFila(tipoFC *filaAux) {
  int i = filaAux->primeiro ;
  for (int j = 0 ; j < filaAux->tamanhofila ; j++)
  {
    printf ("%d ", filaAux->elementos[i]) ;
    i++ ;
  }
}*/

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
        insereTarefa(&filaEsC, num) ;
      }if (op == 2)
      {
        removeTarefa(&filaEsC) ;
      }if (op == 3)
      {
        finalizarTarefa(&filaEsC) ;
      }
    }
  }
  listarFila(&filaEsC) ;
  return 0;
}

/* Programa: Lab 05
   Autor: Gustavo Henrique Tavares Isobe - RA: 158552
   Versao: 1.0 - 17/11/2022 - 20:20h
*/

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 100
//1: inserir elemento
//2: remover ultimo elemento
//3: mudar o primeiro elemento para o final

// ########################## TAD X.h ######################################

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
  filaAux->tamanhofila = 0 ;
  for (i = 0; i < tamanhoMAX; i++)
    filaAux->elementos[i] = 0;
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

void insereTarefa(tipoFC *filaAux,int info) { // se a fila estiver vazia insere o primeiro elemento
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0 ;
    filaAux->ultimo = 0 ;
    filaAux->elementos[0] = info ;
    filaAux->tamanhofila++;
  }else if (filaCheia(filaAux) == 0) { // se a fila não estiver cheia podemos inserir
    int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = info ;
    filaAux->ultimo = posicao ;
    filaAux->tamanhofila++ ;
  }else
    printf("cheia") ; 
}

// ###################### Funcoes e Procedimentos do programa ##############

void removeTarefa (tipoFC *filaAux)
{
  if (filaCheia(filaAux) == 0)
  {
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro + 1 ;
    filaAux->tamanhofila --;
  }else
    printf ("vazia\n") ;
}

void finalizarTarefa(tipoFC *filaAux)
{
  if (filaVazia(filaAux) == 0 && filaAux->tamanhofila > 1)
  {
    int posicao = posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = filaAux->elementos[filaAux->primeiro] ;
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro+1 ;
    filaAux->ultimo = posicao ;
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
}

// ############################ Principal ###################################
  
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
        insereTarefa(&filaEsC, num) ;
      }if (op == 2)
      {
        removeTarefa(&filaEsC) ;
      }if (op == 3)
      {
        finalizarTarefa(&filaEsC) ;
      }
    }
  }
  listarFila(&filaEsC) ;
  return 0;
}

/* Programa: Lab 05
   Autor: Gustavo Henrique Tavares Isobe - RA: 158552
   Versao: 1.0 - 17/11/2022 - 20:20h
*/

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 1000

// ########################## TAD X.h ######################################

struct filaCircular{
  int primeiro;
  int ultimo;
  int tamanhofila;
  int elementos[tamanhoMAX];
};
typedef struct filaCircular tipoFC;

void inicializaFila(tipoFC *filaAux) {
  int i;
  filaAux->primeiro = -1;
  filaAux->ultimo = -1;
  filaAux->tamanhofila = 0 ;
  for (i = 0; i < tamanhoMAX; i++)
    filaAux->elementos[i] = 0;
}

int filaVazia(tipoFC *filaAux) {
  if ((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1))
    return 1 ; 
  else
    return 0 ;
}

int filaCheia(tipoFC *filaAux) {
  if (((filaAux->ultimo + 1) % tamanhoMAX) == filaAux->primeiro)
    return 1 ;
  else
    return 0 ;
}

void insereTarefa(tipoFC *filaAux,int info) { // se a fila estiver vazia insere o primeiro elemento
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0 ;
    filaAux->ultimo = 0 ;
    filaAux->elementos[0] = info ;
    filaAux->tamanhofila++;
  }else if (filaCheia(filaAux) == 0) { // se a fila não estiver cheia podemos inserir
    int posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = info ;
    filaAux->ultimo = posicao ;
    filaAux->tamanhofila++ ;
  }
}

// ###################### Funcoes e Procedimentos do programa ##############

void removeTarefa (tipoFC *filaAux)
{
  if (filaCheia(filaAux) == 0)
  {
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro + 1 ;
    filaAux->tamanhofila --;
  }else
    printf ("vazia\n") ;
}

void finalizarTarefa(tipoFC *filaAux)
{
  if (filaVazia(filaAux) == 0 && filaAux->tamanhofila > 1)
  {
    int posicao = posicao = ((filaAux->ultimo + 1) % tamanhoMAX) ;
    filaAux->elementos[posicao] = filaAux->elementos[filaAux->primeiro] ;
    filaAux->elementos[filaAux->primeiro] = 0 ;
    filaAux->primeiro = filaAux->primeiro+1 ;
    filaAux->ultimo = posicao ;
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
}

// ############################ Principal ###################################
  
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
        insereTarefa(&filaEsC, num) ;
      }if (op == 2)
      {
        removeTarefa(&filaEsC) ;
      }if (op == 3)
      {
        finalizarTarefa(&filaEsC) ;
      }
    }
  }
  listarFila(&filaEsC) ;
  return 0;
}
