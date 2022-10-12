/* Programa: Lab 01
   Autor: Gustavo Henrique Tavares Isobe - RA: 158552
   Versao: 1.0 - 12/10/2022
*/

// ##################### Bibliotecas Externas ##############################

#include<stdio.h>
#include <stdlib.h>
#define MAX 100

// ########################## TAD X.h ######################################

struct listaLivros{
    int livros_reservados[MAX] ;
    int livros_retirados[MAX] ;
};
typedef struct listaLivros livros ;

struct listaES{
    int ultimo;
    int tamanhoLista;
    int lista[MAX];
};
typedef struct listaES tipoListaES;

void inicializaLista (tipoListaES *listaAux)
{
    int i;
    listaAux->tamanhoLista = 0 ;
    for (i = 0 ; i < MAX ; i++){
        listaAux->lista[i] = 0 ;
    }
    listaAux->ultimo = 0;
}

void insereElemento (tipoListaES *listaAux)
{
    listaAux->tamanhoLista++ ;
    scanf("%d", &listaAux->lista[listaAux->tamanhoLista-1]);
    listaAux->ultimo = listaAux->tamanhoLista - 1 ;
}

// ###################### Funcoes e Procedimentos do programa ##############

void imprimi (tipoListaES *listaAux,livros *listaReg, int t)
{
    int i, j, k, x, aux ;
    int cont_rs = 0, cont_rt = 0, qtd_reserva = 0 ;
    for (i = 0 ; i < t ; i += 2)
    {
        aux = 0 ;
        if (listaAux->lista[i] == 1)
        {
            if (qtd_reserva < 10){
                aux = listaAux->lista[i+1] ;
                if (aux > 0 && aux <= 100)
                {
                    listaReg->livros_reservados[cont_rs] = aux ;
                    printf ("Sua reserva foi realizada\n") ;
                    cont_rs++ ;
                    qtd_reserva++ ;
                }
            }else
                printf ("Lista de reserva cheia\n") ;
        }else
        if (listaAux->lista[i] == 2)
        {
            x = 0 ;
            for (j = 0 ; j < cont_rs ; j++)
            {
                if (listaReg->livros_reservados[j] == listaAux->lista[i+1])
                {
                    x =+ 1 ;
                    aux = listaReg->livros_reservados[j] ;
                }
            }
            if (x == 1)
            {
                listaReg->livros_retirados[cont_rt] = aux ;
                printf ("O livro foi retirado com sucesso\n") ;
                cont_rt ++ ;
                qtd_reserva --;
            }else
                printf ("Voce nao possui reserva desse livro\n") ;
        }
    }
    printf ("Voce realizou %d reservas e %d retiradas", cont_rs, cont_rt) ;
}

// ############################ Principal ###################################

int main (){
    tipoListaES minhaLista ;
    livros regBiblioteca ;
    inicializaLista(&minhaLista) ;
    int t, i ;
    scanf ("%d", &t) ;
    t = t * 2 ;
    for (i = 0 ; i < t ; i++)
    {
        insereElemento(&minhaLista) ;
    }
    imprimi (&minhaLista, &regBiblioteca, t) ;
    return 0;

}