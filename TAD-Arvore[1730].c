/*
Parte Teórica:
Árvore:
        Estrutura de dados que possui uma relação de hierarquia;
        Conjunto finito de um ou mais nós (vértices) tais que:
            -Existe um nó denominado RAIZ
            -Os demais nós foramam conjuntos separados que também são árvores (sub-árvores)
        Definições:
            ~ARESTA: Linha que liga dois nós
                Com Orientação(->): Grafo/Árvore DIRIGIDO(A)
                Sem Orientação(--): Grafo/Árvore NÃO DIRIGIDO(A)
            ~CAMINHO ENTRE DOIS NÓS: se a partir do primeiro chegar no segundo percorrendo as arestas.
                As arestas percorridas entre os dois nós são o tamanho do caminho
                NÃO EXISTEM CICLOS EM UMA ÁRVORE
                -Se o caminho começa em A e vai pra B:
                    A é um nó ANCESTRAL de B
                    B é um nó DESCENDENTE de A
                    Se o tamanho é de 1 aresta: A é pai de B e B é filho de A
                    Dois nós que são nós filhos do mesmo nó são NÓS IRMÃOS
                    Cada nó só pode ter UM PAI
            ~Grau de um nó: Número de nós filhos
            ~Nós que não possuem descentes: FOLHA (grau zero)
            ~Nível de um nó: Arestas existentes no caminho entre a raiz e o próprio nó
                            Raiz: Nível = 0
                            Estando um nó no nível n, seus filhos estarão em n+1
            ~Altura de um nó = número de nós do maior caminho dele até um de seus descendentes
                            (quantos nós existem de um nó até uma de suas folhas)
                Folhas possuem altura 1
            ~GRAU DA ÁRVORE = grau do nó de maior grau da árvore
            ~PROFUNDIDADE DA ÁRVORE = maior nível da árvore
            ~FLORESTA = conjunto de árvores :v
            ~Árvore Homogênea = todos os nós possuem o mesmo tipo de informação
            ~       Heterogênea = tipos dif. de info

Árvore Binária:
    Especialização de árvores:
    -TODOS os nós possuem, no máx, GRAU 2
    -Compreende 3 sub-conjuntos: Raiz, Sub-árvore da direita e da a daesquerda
    Definições iniciais:
        -Estritamente binárias: TODOS os nós não folhas possuem as sub-árvores da esquerda e da direita não vazias
                                Ou seja, 0 ou 2 filhos
        -Binária completa: Estritamente binária mas todos os nós folhas estão no em n ou em n-1;
        -Binária cheia: completa, mas os nós que são folhas estão todos no mesmo nível n
    -PERCURSOS:
        3 Ordens possíveis:
            ~Pré-Ordem (r, e, d):
                visite a raiz ANTES de "e" e "d"
            ~Em Ordem (e, r, d):
                visite primeira a sub-árvore "e", depois a RAIZ e depois a sub-árvore "d"
            ~Pós-Ordem (e, d, r):
                visite a raiz DEPOIS da sub-árvores "e" e "d"
        São definidas recursivamente em função da raiz(r), da sub-árvore esquerda(e) e da sub-árvore direita(d)


*/
//Implementação Dinâmica:
#include <stdio.h>
#include <stdlib.h>

struct noArvoreBinaria
{
    char info;
    struct noArvoreBInaria* esq;
    struct noArvoreBInaria* dir;
};
typedef struct noArvoreBinaria tipoNoAB;

//Inicialização:
void inicializa (char c, tipoNoAB *arvoreAux)
{
    arvoreAux->info = c;
    arvoreAux->esq = NULL;
    arvoreAux->dir = NULL;
}

//Cria e retorna o endereço do Nó
tipoNoAB* insereNo (char c)
{
    tipoNoAB* novo = (tipoNoAB*) calloc(1,sizeof(tipoNoAB));
    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insereRecursivo(tipoNoAB *raiz, char c)
{
    int lado;

    if(raiz == NULL)
    {
        raiz = insereNo(c);
    }
    else
    {
        print("Esquerda(0), direita(1):\n");
        scanf("%d", &lado);
        if(lado == 0)
        {
            if(raiz->esq == NULL)
            {
                raiz->esq = insereNo(c)
            }
        }
    }
}

void imprime ( tipoNoAB *aux )
{
    if (aux!= NULL)
        printf("%c", aux->info);
    if (aux->dir!= NULL)
        imprime(aux->dir);
    if (aux->esq!= NULL)
        imprime(aux->esq);
}

