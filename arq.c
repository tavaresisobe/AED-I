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
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    char descricao[50];
    int preco;
    int quantidade;
}produto ;

void main ()
{
    produto reg [MAX];
    int i ;
    FILE *arq ;
    arq = fopen("myfile1.bin", "r+b") ;
    fseek(arq, 0, SEEK_END) ;
    char recovery[1000] ;
    if (arq != NULL)
    {
        for (i = 0 ; i < MAX ; i++)
        {
            fscanf(arq,"%s %s", recovery, reg[i].descricao) ;
            fscanf(arq,"%s %d", recovery, &reg[i].preco) ;
            fscanf(arq,"%s %d", recovery, &reg[i].quantidade) ;
        }
        fclose(arq) ;
    }else
    {
        printf ("Nao Leu") ;
    }
    for (i = 0 ; i < MAX ; i++)
    {
        printf ("Descricao: %s ", reg[i].descricao) ;
        printf ("Preco: %d ", reg[i].preco) ;
        printf ("Qtd: %d\n", reg[i].quantidade) ;
    }
    printf ("Recovery: %s\n", recovery) ;
}
*/
