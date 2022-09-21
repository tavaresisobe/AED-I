#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
  int numM[100] ;
  int qtdM[100] ; 
  float numUSA_M[100] ;
}SapatoM;

typedef struct{
  int numF[100] ;
  int qtdF[100] ;
  float numUSA_F[100] ;
}SapatoF ;

float feminino(float a){
  float converte = ((((a * 6.67) + 19)/25.4) * 3) - 23 ;
  float f = ceil(converte) ;
  f = f - converte ;
  if (f >= 0.0 && f <= 0.20){    //se vd > 0,8
      return ceil(converte) ;
  }else
  if (f > 0.20 && f <= 0.6){    //se 0,4 <= vd < 0,8
      return floor(converte) + 0.5 ;
  }else
  if (f > 0.60 && f <= 1){    //se 0 <= vd < 0,4
       return floor(converte) ;
  }
}
float masculino(int b){
  float converte = ((((b * 6.67) + 19)/25.4) * 3) - 24 ;
  float m = ceil(converte) ;
  m = m - converte ;
  if (m >= 0.0 && m <= 0.20){    //se vd > 0,8
      return ceil(converte) ;
  }else
  if (m > 0.20 && m <= 0.6){    //se 0,4 <= vd < 0,8
      return floor(converte) + 0.5 ;
  }else
  if (m > 0.60 && m <= 1){    //se 0 <= vd < 0,4
      return floor(converte) ;
  }
}
int main(void) {
  SapatoM lista_M ;
  SapatoF lista_F ;
  int l[100] ;
  int i, j, k, g, test, countF = 0, countM = 0, auxF = 0, auxM = 0 ;
  float aux, iguais[100] ;
  //lendo vetor 1<=L<100 com nmero de testes e pares (N,G)
  for (i = 0 ; i < 100 ; i++){  
      scanf ("%d", &l[i]) ;
  }
  test = l[0] ; //n de testes
  for (i = 2 ; i <= test * 2 ; i += 2){  //verificando se N vai pertencer a estrutura F ou M 
    if (l[i] == 1){  //G = 1 FEMININO
            lista_F.numF[countF] = l[i-1] ;
            iguais [countF] = feminino(lista_F.numF[countF]) ; 
            if (countF > 1){
                for (k = 0 ; k < countF ; k++){
                    for (j = k + 1 ; j < countF ; j++){
                        if (iguais[k] == iguais[j]){
                            g = k ;
                            lista_F.qtdF[g] += 1 ;
                            countF += 1 ;
                        }
                    }
                }
            }else{
                lista_F.numUSA_F[countF] = feminino(lista_F.numF[countF]) ;
                lista_F.qtdF[countF] = 1 ;
                auxF = lista_F.numF[countF] ;
                countF += 1 ;
            }
    }else
    if (l[i] == 0){  //G = 0 MASCULINO
       /* if (l[i-1] == auxM){
            lista_M.qtdM[countM-1] += 1 ;
        }else{*/
            lista_M.numM[countM] = l[i-1] ;
          /*  if (countM > 1){
                
            }*/
            
            lista_M.numUSA_M[countM] = masculino(lista_M.numM[countM]) ;
            lista_M.qtdM[countM] = 1 ;
            auxM = lista_M.numM[countM] ;
            countM += 1 ;
        }
    }
  //}
  //gambiarra (para impressão) nas próximas linhas:
  if (countF > 0){
      printf ("F ") ;
    for (i = 0 ; i < countF ; i++){
        for (j = 0 ; j < countF ; j++){
             if (lista_F.numUSA_F[i] < lista_F.numUSA_F[j]){
                 aux = lista_F.numUSA_F[i] ;
                 lista_F.numUSA_F[i] = lista_F.numUSA_F[j] ;
                 lista_F.numUSA_F[j] = aux ;
                 aux = lista_F.qtdF[i] ;
                 lista_F.qtdF[i] = lista_F.qtdF[j] ;
                 lista_F.qtdF[j] = aux ;
             }
        }
    }
    for (i = 0 ; i < countF ; i++){
      printf ("%.1f-(%d) ", lista_F.numUSA_F[i], lista_F.qtdF[i]) ;
    }  
    printf ("\n") ;
  }
  if (countM > 0){
      printf ("M ") ;
    aux = 0.0 ;
    for (i = 0 ; i < countM ; i++){
        for (j = 0 ; j < countM ; j++){
             if (lista_M.numUSA_M[i] < lista_M.numUSA_M[j]){
                 aux = lista_M.numUSA_M[i] ;
                 lista_M.numUSA_M[i] = lista_M.numUSA_M[j] ;
                 lista_M.numUSA_M[j] = aux ;
                 aux = lista_M.qtdM[i] ;
                 lista_M.qtdM[i] = lista_M.qtdM[j] ;
                 lista_M.qtdM[j] = aux ;
             }
        }
    }
    for (i = 0 ; i < countM ; i++){
        printf ("%.1f-(%d) ", lista_M.numUSA_M[i], lista_M.qtdM[i]) ; ;
    }
  }
  return 0 ;
}