/* Programa: Laboratório 1
   Autor: Gustavo Henrique Tavares Isobe
   Versão 10/10/2022 22:35
*/

https://wagnergaspar.com/lista-encadeada-com-a-linguagem-c/


// ##################### Bibliotecas Externas ##############################


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


// ########################## TAD X.h ######################################


struct listaES{
    int ultimo ;
    int tamanhoLista ;
    int lista[MAX] ;
}
typedef struct listaES tipoListaES ;


reservar() ;

retirar() ;


// ###################### Funcoes e Procedimentos do programa ##############



// ############################ Principal ###################################


int main ()
{
    tipoListaES minhaLista ;
    int i, j, t, aux arranjo[MAX] ;
    t = scanf ("%d", &aux) * 2 ;
    int arranjo[t] ;
    
    for (i = 0, j = 0 ; i < t, j < t ; i++, j+2)
    {
        scanf ("%d", &arranjo[i]) ;
            if (arranjo[j] == 1){     //1 para reservar
                reservar() ;
            }else
            if (arranjo[j] == 2){     //2 para retirar
                retirar() ;
            }
    }
    
    return 0 ;
}

/*
* Programa: Laboratório 1
   Autor: Gustavo Henrique Tavares Isobe
   Versão 10/10/2022 22:35
*/


// ##################### Bibliotecas Externas ##############################


#include <stdio.h>
#include <stdlib.h>
#define MAX 100


// ########################## TAD X.h ######################################


struct listaES{
    int ultimo ;
    int tamanhoLista ;
    int lista[MAX] ;
}


// ###################### Funcoes e Procedimentos do programa ##############

reservar() ;

retirar() ;

// ############################ Principal ###################################

typedef struct listaES tipoListaES ;

int main ()
{
    int t, aux ;
    scanf ("%d", &aux) ;
    t = aux * 2 ;
    printf ("numero de elementos que serao lidos: %d", t) ;
    tipoListaES minhaLista ;

    minhaLista.lista[t] = NULL ;
    minhaLista.tamanhoLista = 0 ;

  /*  for (i = 0, j = 0 ; i < t, j < t ; i++, j+2)
    {
        scanf ("%d", &arranjo[i]) ;
            if (arranjo[j] == 1){     //1 para reservar
                reservar() ;
            }else
            if (arranjo[j] == 2){     //2 para retirar
                retirar() ;
            }
    }
    */
    return 0 ;
}

*/
