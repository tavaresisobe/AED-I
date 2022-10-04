/*http://www.ic.uff.br/~ccaetano/aulas/PROG1_17_Arquivos_em_C.pdf*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct{
    char descricao[50];
    int preco;
    int quantidade;
}produto ;

void main ()
{
    int i ;
    produto reg[MAX] ;
    //printf ("Reage\n") ;
    FILE *arq ;
    arq = fopen("myfile1.bin", "rb") ;
    if (arq != NULL)
    {
        for (i = 0 ; i < MAX ; i++)
        {
            fscanf(arq,"%s %d %d", reg[i].descricao, &reg[i].preco, reg[i].quantidade) ;
            printf("%s %d %d\n", reg[i].descricao, &reg[i].preco, reg[i].quantidade) ;
        }
        fclose(arq) ;
    }else
    {
        printf ("Nao Leu") ;
    }
}
