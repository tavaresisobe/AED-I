#include <stdio.h>
#include <stdlib.h>
//Número máximo de elementos
#define tamanhoMax 100
// Estrutura PES
struct pilha {
  int elementos[tamanhoMax];
  int topo;
};
typedef struct pilha tipoPilha;

void inicializaPilha(tipoPilha *pilhaAux)
{
  int i ;
  for (i = 0 ; i<=tamanhoMax - 1; i++)
  {
    pilhaAux->elementos[i] = 0;
    pilhaAux->topo = -1;
  }
}

int empilhar (tipoPilha *pilhaAux, int val)
{
  if (pilhaAux->topo >= tamanhoMax-1) // pilha cheia
    return -1; // aborta a funcao
  else
  {
    pilhaAux->topo++;
    pilhaAux->elementos[pilhaAux->topo] = val;
    return 0 ; // sucesso
  }
}

void listarPilha(tipoPilha *pilhaAux)
{
  int i ;
  for (i = 0 ; i < tamanhoMax ; i++)
  {
    printf ("%d ", pilhaAux->elementos[i]) ;  
  }
  printf ("\n") ;
}

int main ()
{
  tipoPilha pilhaEs ;
  int i, x, num, aux; 
  scanf ("%d", &x) ;

  if (x > 0)
  {
    inicializaPilha(&pilhaEs) ;
    for (i = 0 ; i < x ; i ++)
    {
      scanf ("%d", &num) ;
      empilhar(&pilhaEs, num) ;
      listarPilha(&pilhaEs) ;
    }
  }
  

  return 0 ;
}

/*

void bin(tipoPilha *pilhaAux)
{
  printf ("\nBinario: \n") ;
  int i, j, num, count = 0;
  int bin[tamanhoMax] ;
  for (i = 0 ; i <= pilhaAux->topo ; i++)
  {
    count = 0 ;
    num = pilhaAux->elementos[i] ;
    if (num == 0)
      bin[count] = 0 ;
    else{
      while(num > 0){
		    // obtém o resto da divisão de num por 2
		    bin[count] = num % 2;
		    count++;
		    num = num / 2;
      }
    }
    for (j = count ; j > 0 ; j --)
    {
      printf ("%d", bin[j]) ;
    }
    printf ("\n") ;
  }
}*/

/*
#include <stdio.h>

int main ()
{
    int x, i, count = 0 ;
    int vet[50] ;
    scanf ("%d", &x) ;
    printf ("%d em binario eh: ", x) ;
    if (x == 0)
        vet[count] = 0 ;
    else{
        while(x > 0)
        {
            vet[count] = x % 2;
		    count++;
		    x = x / 2;
        }
    }
    for (i = count - 1 ; i >= 0 ; i--)
    {
        printf("%d", vet[i]) ;
    }
    return 0 ;
}
*/
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
