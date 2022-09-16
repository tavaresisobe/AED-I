/* #include <stdio.h>
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
/*int feminino(int aux){
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
}*/


#include <stdio.h>
#include <stdlib.h>
/*1 = feminino
0 = masculino*/

void feminino(int a){
    double convert = (((a + 19)/25,4) * 3) - 23 ;
    printf("F %lf\n", convert) ;
}

void masculino(int b){    
    double convert = (((b + 19)/25,4) * 3) - 24 ;
    printf("M %lf\n", convert) ;
}

int main(){
  int l[] = {3, 35, 1, 40, 1, 40, 1} ;
  int i, j, teste, cont = 0, aux = 0, size = 0 ; 
  teste = l[0] ;
  size = sizeof(l) / sizeof(l[0]) ;
  printf ("%d\n", teste) ;
  printf ("%d\n", size) ;

  for (i = 2 ; i <= size ; i += 2){
    if (l[i] == 1){
      aux = l[i-1] ;
      feminino(aux) ;
    }else
      if (l[i] == 0){
        aux = l[i-1] ;
        masculino(aux) ;
      }
  }
/*  while(cont <= teste)
  {
    for (i = 1 ; i <= (teste * 2) ; i+2){
      for (j = 2 ; j <= (teste * 2) ; j+2){
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
    cont++ ;
  }*/
    return 0 ; 
}

#include <stdio.h>
#include <stdlib.h>
/*1 = feminino
0 = masculino*/

void feminino(int a){
  printf("%d\n", a) ;
  double convert = (((a + 19)/25,4) * 3) - 23 ;
  printf("F %lf\n", convert) ;
}

void masculino(int b){ 
  printf("%d\n", b) ;
  double convert = (((b + 19)/25,4) * 3) - 24 ;
  printf("M %lf\n", convert) ;
}

int main(){
  int l[] = {3, 35, 1, 40, 1, 40, 1} ;
  int i, j, teste, cont = 0, aux = 0, size = 0 ; 
  teste = l[0] ;
  size = sizeof(l) / sizeof(l[0]) ;
  printf ("%d\n", teste) ;
  printf ("%d\n", size) ;

  for (i = 2 ; i <= size ; i += 2){
    if (l[i] == 1){
      aux = l[i-1] ;
      feminino(aux) ;
    }else
      if (l[i] == 0){
        aux = l[i-1] ;
        masculino(aux) ;
      }
  }
/*  while(cont <= teste)
  {
    for (i = 1 ; i <= (teste * 2) ; i+2){
      for (j = 2 ; j <= (teste * 2) ; j+2){
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
    cont++ ;
  }*/
    return 0 ; 
}
#include <stdio.h>
#include <stdlib.h>
/*1 = feminino
0 = masculino*/

typedef struct{
  int num ; 
  double numUSA ;
  int genero ;
}Sapato ;

void feminino(int a){
  printf("%d\n", a) ;
  float convert = (((230 + 19)/25.4) * 3) - 23 ;
  printf("F %.2lf\n", convert) ;
}

void masculino(int b){ 
  printf("%d\n", b) ;
  float convert = (((b + 19)/25.4) * 3) - 24 ;
  printf("M %.2lf\n", convert) ;
}

int main(){
  float = num_mm_homens[] = {23, 23.5, 24.5, 25.5, 26, 27, 27.5, 28.5, 29.5, 30, 30.5} ;
  float = num_mm_mulheres[] = {23, 23.5, 24, 25, 26, 27, 27.5} ;
  int l[] = {3, 35, 1, 40, 1, 40, 1} ;
  int i, j, teste, size = 0 ; 
  teste = l[0] ;
  Sapato lista[teste] ;
  size = sizeof(l) / sizeof(l[0]) ;
  for (j = 0, i = 2 ; j < teste, i <= size ; j++, i += 2){
    if (l[i] == 1){
      lista[j].genero = 1 ;
      lista[j].num = l[i-1] ;
      feminino(lista[j].num) ;
    }else
    if (l[i] == 0){
      lista[j].genero = 0 ;
      lista[j].num = l[i-1] ;
      masculino(lista[j].num) ;
    }
  }
  return 0 ; 
}
