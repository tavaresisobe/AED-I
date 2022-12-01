#include <stdio.h>

struct noArvoreBB {
  int chave ;
  struct noArvoreBB* esq;
  struct noArvoreBB* dir;
};
typedef struct noArvoreBB tipoABB;

void inicializa (int c, tipoABB *arvoreAux)
{
  arvoreAux->chave = c;
  arvoreAux->esq = NULL;
  arvoreAux->dir=NULL;
}

tipoABB* insereNo(int c) {
  tipoABB* novo = ()malloc(sizeof(tipoABB));
  novo->chave = c ;
  novo->dir = NULL;
  novo->esq= NULL;
  return novo;
}

void insereABB (int chave, tipoABB *Aux){
  if (chave < Aux->chave) {
    if (Aux->esq == NULL)
      Aux->esq = insereNo (chave);
    else insereABB (chave, Aux->esq);
  }else 
  if (chave > Aux->chave)
    if (Aux->dir == NULL)
      Aux->dir = insereNo (chave) ;
    else insereABB (chave, Aux->dir) ;
  else printf("Elemento Existente!") ;
}

tipoABB* removeABB(tipoABB *Aux, int info)
{
  tipoABB *temp ;
  if (Aux == NULL)
    return NULL ;
  else
  if (Aux->chave > info)
  {
    Aux-> esq = removeABB(Aux->esq, info) ; 
  }else 
  if (Aux->chave < info)
  {
    Aux->dir = removeABB(Aux->dir, info) ;
  }else{
    if ((Aux->esq != NULL) && (Aux->dir != NULL))
    {
      temp = maiorValor(Aux->esq) ;
      Aux->chave = temp->chave ;
      temp->chave = info ;
      Aux->esq = removeABB(Aux->esq, info) ;
    }else if (Aux->esq != NULL){
            temp = Aux ;
            Aux = Aux->esq ;
            free(temp) ;
          }else if (Aux->dir != NULL){
                  temp = Aux ;
                  Aux = Aux->dir ;
                  free(temp) ;
                }else
                    free(Aux) ;
                    return NULL ;
  }
}

int main(void) {
  int entradas, x, raiz ;
  scanf ("%d", &entradas) ;
  if (entradas > 0)
  {
    scanf ("%d", &x) ;
    inicializa() ;
  }
  
  return 0;
}
