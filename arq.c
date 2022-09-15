#include <stdio.h>
#define MAX 100
#include <stdlib.h>
//CVh = [( (comprimento em (mm) + 19) / 25, 4) × 3] − 24 massculina
//CVh = [( (comprimento em (mm) + 19) / 25, 4) × 3] − 23 feminina
/*A primeira linha contém um valor inteiro L, 1 ≤ L ≤ 100, que representa a
quantidade de sapatos encomendada.
2. Em cada uma das L linhas seguintes é dado um par (N, G) de valores inteiros.
O par indica a numeração no sistema brasileiro N, 35 ≤ N ≤ 45, que deve
ser comprada para o gênero G, em que G recebe 0 para se referir ao gênero
masculino e 1 para feminino.
1 = fe,inino
0 = masculino*/
int feminino(int aux){
    int covert = ((aux + 19) / 25,4) × 3) − 23 ;
    printf("F %d", aux) ;
    return 0;
}
int masculino(int aux){
    
    int convert = ((aux + 19) / 25,4) × 3) − 24;
    printf("M %d", aux) ;
    return 0;
}

int main(){

    int l[MAX], i, teste ; 
    for (i = 0 ; i < MAX ; i++)
    {
        scanf("%d",&l[i]) ;
    }
    teste = l[0] ;
    while(teste > 0)
    {
        for (i = 1 ; i <= MAX ; i+2)
        {
            for (j = 2 ; j <= MAX ; j+2)
            {
                if (j == 0)
                {
                    aux = l[i] ;
                    masculino(aux) ;
                }else
                if (j == 1)
                {
                    aux = l[i] ;
                    feminino(aux) ;
                }
            }
        }
        teste -- ;
    }
    return 0 ; 
}
