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
  SapatoM M ;
  SapatoF F ;
  
  int l[100] ;
  int i, j, test, g = 0, countF = 0, countM = 0 ;
  float vet [100], aux ;
 
  for (i = 0 ; i < 100 ; i++)
  {  
      scanf ("%d", &l[i]) ;
  }
  test = l[0] ;
  for (i = 2 ; i <= test * 2 ; i += 2)
  {
      if (l[i] == 1)
      {
          if (l[i-1] >= 35 && l[i-1] <= 45)
          {
              F.numF[countF] = l[i-1] ;
          }
          countF ++ ;
      }else
      if (l[i] == 0)
      {
          if (l[i-1] >= 35 && l[i-1] <= 45)
          {
              M.numM[countM] = l[i-1] ;
          }
          countM ++ ;
      }
  }
    if (countF > 0)
    {
        for (i = 0 ; i < countF ; i++)
        {
            vet [i] = feminino(F.numF[i]) ;
        }
      
    }
    for (i = 0 ; i < countF ; i++)
    { 
        for (j = i + 1 ; j < countF ; j++)
        {
            if (vet[i] > vet[j])
            {
                aux = vet[i] ;
                vet[i] = vet[j] ;
                vet[j] = aux ;
            }
        }
    }
    for (i = 0 ; i <= countF ; i++) 
    {
        for (j = i+1 ; j <= countF ; j++)
        {
            if (vet[i] == vet[j])
            {
                F.qtdF[i] += 1 ;
                printf ("%d\n %d\n", i, F.qtdF[i]) ;
            }else{
                F.numUSA_F[i] = vet[i] ;
                F.qtdF[i] += 1 ;
            }
        }
    }
  printf ("%d\n ", countF) ;
  for (i = 0 ; i < countF ; i++){
      printf ("%.1f-(%d) ", F.numUSA_F[i], F.qtdF[i]) ;
    }  
  return 0 ;
  }