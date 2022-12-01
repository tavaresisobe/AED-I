#include <stdio.h>
#include <stdlib.h>
/*
struct Arvore
{
    struct arvoreBinariaBusca *raiz;
};
typedef struct Arvore tipoArvore;
*/
struct noArvoreBinaria
{
    int chave;
    struct noArvoreBInaria* esq;
    struct noArvoreBInaria* dir;
};
typedef struct noArvoreBinaria tipoABB;

//Inicialização:
void inicializa (int c, tipoABB *arvoreAux)
{
  arvoreAux->chave = c;
  arvoreAux->esq = NULL;
  arvoreAux->dir=NULL;

}

//Cria e retorna o endereço do Nó
tipoABB* insereNo (int c)
{
    tipoABB* novo = (tipoABB*)calloc(1,sizeof(tipoABB));
    novo->chave = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insereABB (int chave, tipoABB *Aux){
  if (chave < Aux->chave) {
    if (Aux->esq == NULL)
      Aux->esq = insereNo (chave);
    else insereABB (chave, Aux->esq);
    }else if (chave > Aux->chave)
            if (Aux->dir == NULL)
              Aux->dir = insereNo (chave);
            else insereABB (chave, Aux->dir);
          else printf("Elemento Existente!");

}

void imprime (tipoABB *aux)
{
    if (aux!= NULL)
        printf("%d", aux->chave);
    if (aux->dir!= NULL)
        imprime(aux->dir);
    if (aux->esq!= NULL)
        imprime(aux->esq);
}

int main ()
{
  int i, x, testes, operacao ;
  tipoABB *raiz = (tipoABB*) calloc(1, sizeof(tipoABB));
  scanf ("%d", &x) ;
  inicializa(x, raiz);
  scanf ("%d", &testes) ;
  for (i = 0 ; i < testes ; i++)
  {
    scanf ("%d", &operacao) ;
    if (operacao == 1)
    {
      insereABB() ;
    }else if (operacao == 2){
      
    }
  }
  return 0 ;
}
