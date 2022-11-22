#include <stdio.h>
#include <stdlib.h>
//Número máximo de elementos
#define tamanhoMax 5
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

