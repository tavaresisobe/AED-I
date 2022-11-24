/* Programa: lab 5
   Autor: Gustavo Henrique Tavares Isobe -  RA: 158552 
   Versao: 2.0 - 23/11/2022 - 22:11 h
*/

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamanhoMax 100

// ########################## TAD X.h ######################################

struct pilha {
  int elementos[tamanhoMax];
  int topo;
};
typedef struct pilha tipoPilha;

void inicializaPilha(tipoPilha *pilhaAux) {
  int i;
  for (i = 0; i <= tamanhoMax - 1; i++) {
    pilhaAux->elementos[i] = 0;
    pilhaAux->topo = -1;
  }
}

int empilhar(tipoPilha *pilhaAux, int val) {
  if (pilhaAux->topo >= tamanhoMax - 1) 
    return -1;                          
  else {
    pilhaAux->topo++;
    pilhaAux->elementos[pilhaAux->topo] = val;
    return 0;
  }
}

// ###################### Funcoes e Procedimentos do programa ##############

void bin() ;
void bin_reverso() ;

void bin(tipoPilha *pilhaAux)
{
  int i, j, num, count = 0;
  int bin[50] ;
  for (i = 0 ; i <= pilhaAux->topo ; i++)
  {
    count = 0 ;
    num = pilhaAux->elementos[i] ;
    printf ("%d ", num) ;
    if (num == 0)
      bin[count] = 0 ;
    else{
      while(num > 0){
		    bin[count] = num % 2;
		    count++;
		    num = num / 2 ;
      }
    }
    for (j = count - 1 ; j >= 0 ; j --)
    {
      printf ("%d", bin[j]) ;
    }
    printf (" ") ;
    bin_reverso(&bin, count) ;
    printf ("\n") ;
  }
}

void bin_reverso(int *bin, int count)
{
  int i = 0, j ;
  int dec, bin_r[50] ;
  for (j = count - 1 ; j >= 0 ; j --)
  {
    if (bin[j] == 1)
    {
      bin_r[i] = 0 ;
      i++ ;
    }else if (bin[j] == 0)
          {
            bin_r[i] = 1 ;
            i++ ;
          }
  }
  for (i = 0 ; i < count ; i++)
  {
    printf ("%d", bin_r[i]) ;  
  }
  i = 0 ;
  while (count--)
  {
    if (bin_r[count] == 1 || bin_r[count] == 0)
    {
      dec = dec + pow(2,i++) * (bin_r[count] - 0);
    }
  }
  printf (" %d", dec) ;
}

// ############################ Principal ###################################

int main() {
  tipoPilha pilhaEs;
  int i, x, num, aux;
  scanf("%d", &x);

  if (x > 0) {
    inicializaPilha(&pilhaEs);
    for (i = 0; i < x; i++) {
      scanf("%d", &num);
      empilhar(&pilhaEs, num);
    }
    bin(&pilhaEs) ;
  }

  return 0;
}



---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// Número máximo de elementos
#define tamanhoMax 100
// Estrutura PES
struct pilha {
  int elementos[tamanhoMax];
  int topo;
};
typedef struct pilha tipoPilha;

void inicializaPilha(tipoPilha *pilhaAux) {
  int i;
  for (i = 0; i <= tamanhoMax - 1; i++) {
    pilhaAux->elementos[i] = 0;
    pilhaAux->topo = -1;
  }
}

int empilhar(tipoPilha *pilhaAux, int val) {
  if (pilhaAux->topo >= tamanhoMax - 1) // pilha cheia
    return -1;                          // aborta a funcao
  else {
    pilhaAux->topo++;
    pilhaAux->elementos[pilhaAux->topo] = val;
    return 0; // sucesso
  }
}
void bin_reverso() ;
void bin(tipoPilha *pilhaAux)
{
  int i, j, num, count = 0;
  int bin[50] ;
  for (i = 0 ; i <= pilhaAux->topo ; i++)
  {
    count = 0 ;
    num = pilhaAux->elementos[i] ;
    printf ("%d ", num) ;
    if (num == 0)
      bin[count] = 0 ;
    else{
      while(num > 0){
		    bin[count] = num % 2;
		    count++;
		    num = num / 2 ;
      }
    }
    for (j = count - 1 ; j >= 0 ; j --)
    {
      printf ("%d", bin[j]) ;
    }
    printf (" ") ;
    bin_reverso(&bin, count) ;
    printf ("\n") ;
  }
}

void bin_reverso(int *bin, int count)
{
  int i = 0, j, bin_r[50] ;
  //printf ("\nchegou: \n") ;
  for (j = count - 1 ; j >= 0 ; j --)
  {
    if (bin[j] == 1)
    {
      bin_r[i] = 0 ;
      i++ ;
    }else if (bin[j] == 0)
          {
            bin_r[i] = 1 ;
            i++ ;
          }
  }
  for (i = 0 ; i < count ; i++)
  {
    printf ("%d", bin_r[i]) ;  
  }
  
}

void listarPilha(tipoPilha *pilhaAux) {
  int i;
  for (i = 0; i <= pilhaAux->topo; i++) {
    printf("%d ", pilhaAux->elementos[i]);
  }
  printf("\n");
}

int main() {
  tipoPilha pilhaEs;
  int i, x, num, aux;
  scanf("%d", &x);

  if (x > 0) {
    inicializaPilha(&pilhaEs);
    for (i = 0; i < x; i++) {
      scanf("%d", &num);
      empilhar(&pilhaEs, num);
      //listarPilha(&pilhaEs);
    }
    bin(&pilhaEs) ;
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Número máximo de elementos
#define tamanhoMax 100
// Estrutura PES
struct pilha {
  int elementos[tamanhoMax];
  int topo;
};
typedef struct pilha tipoPilha;

void inicializaPilha(tipoPilha *pilhaAux) {
  int i;
  for (i = 0; i <= tamanhoMax - 1; i++) {
    pilhaAux->elementos[i] = 0;
    pilhaAux->topo = -1;
  }
}

int empilhar(tipoPilha *pilhaAux, int val) {
  if (pilhaAux->topo >= tamanhoMax - 1) // pilha cheia
    return -1;                          // aborta a funcao
  else {
    pilhaAux->topo++;
    pilhaAux->elementos[pilhaAux->topo] = val;
    return 0; // sucesso
  }
}
void bin_reverso() ;
void bin(tipoPilha *pilhaAux)
{
  int i, j, num, count = 0;
  int bin[50] ;
  for (i = 0 ; i <= pilhaAux->topo ; i++)
  {
    count = 0 ;
    num = pilhaAux->elementos[i] ;
    printf ("%d ", num) ;
    if (num == 0)
      bin[count] = 0 ;
    else{
      while(num > 0){
		    bin[count] = num % 2;
		    count++;
		    num = num / 2 ;
      }
    }
    for (j = count - 1 ; j >= 0 ; j --)
    {
      printf ("%d", bin[j]) ;
    }
    printf (" ") ;
    bin_reverso(&bin, count) ;
    printf ("\n") ;
  }
}

void bin_reverso(int *bin, int count)
{
  int i = 0, j ;
  int dec, bin_r[50] ;
  //printf ("\nchegou: \n") ;
  for (j = count - 1 ; j >= 0 ; j --)
  {
    if (bin[j] == 1)
    {
      bin_r[i] = 0 ;
      i++ ;
    }else if (bin[j] == 0)
          {
            bin_r[i] = 1 ;
            i++ ;
          }
  }
  for (i = 0 ; i < count ; i++)
  {
    printf ("%d", bin_r[i]) ;  
  }
  i = 0 ;
  while (count--)
  {
    if (bin_r[count] == 1 || bin_r[count] == 0)
    {
      dec = dec + pow(2,i++) * (bin_r[count] - 0);
    }
  }
  printf (" %d", dec) ;
}

int main() {
  tipoPilha pilhaEs;
  int i, x, num, aux;
  scanf("%d", &x);

  if (x > 0) {
    inicializaPilha(&pilhaEs);
    for (i = 0; i < x; i++) {
      scanf("%d", &num);
      empilhar(&pilhaEs, num);
      //listarPilha(&pilhaEs);
    }
    bin(&pilhaEs) ;
  }

  return 0;
}
