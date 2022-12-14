/* Gustavo Henrique Tavares Isobe - RA: 158552
   Data: 22/09/2022
   AED I - exercício lab 0*/ 

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
  if (f > 0.20 && f <= 0.60){    //se 0,4 <= vd < 0,8
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

void imprime_f (SapatoF f, int count)
{
    int i, j, qtd = 1 ;
    printf ("F ") ;
    for (i = 0 ; i < count ; i++)
    {
        for (j = i + 1 ; j < count ; j++)
        {
            if (f.numUSA_F[i] == f.numUSA_F[j])
            {
                qtd ++ ;
                i++ ;
            }
        }
        printf("%.1f-(%d) ", f.numUSA_F[i], qtd) ;
        qtd = 1 ;
    }
}

void imprime_m (SapatoM M, int count)
{
    int i, j, qtd = 1 ;
    printf ("M ") ;
    for (i = 0 ; i < count ; i++)
    {
        for (j = i + 1 ; j < count ; j++)
        {
            if (M.numUSA_M[i] == M.numUSA_M[j])
            {
                qtd += 1 ;
                i++ ;
            }
        }
        printf("%.1f-(%d) ", M.numUSA_M[i], qtd) ;
        qtd = 1 ;
    }
}

int main(void) {
  SapatoM M ;
  SapatoF F ;
  
  int i, j, test, countF = 0, countM = 0 ;
  float aux ;
  scanf ("%d", &test) ;
 
  int l[test*2] ;
  
  for (i = 0 ; i < test * 2 ; i++)
  {  
      scanf ("%d", &l[i]) ;
  }
  for (i = 1 ; i <= test * 2 ; i += 2)
  {
      if (l[i] == 1)
      {
          if (l[i-1] >= 35 && l[i-1] <= 45)
          {
              F.numF[countF] = l[i-1] ;
              countF ++ ;
          }
      }else
      if (l[i] == 0)
      {
          if (l[i-1] >= 35 && l[i-1] <= 45)
          {
              M.numM[countM] = l[i-1] ;
              countM ++ ;
          }
      }
  }
    if (countF > 0)
    {
        aux = 0 ;
        for (i = 0 ; i < countF ; i++)
        {
            F.numUSA_F[i] = feminino(F.numF[i]) ;
        }

        for (i = 0 ; i < countF ; i++)
        {  
            for (j = i + 1 ; j < countF ; j++)
            {
                if (F.numUSA_F[i] > F.numUSA_F[j])
                {
                    aux = F.numUSA_F[i] ;
                    F.numUSA_F[i] = F.numUSA_F[j] ;
                    F.numUSA_F[j] = aux ;
                }
            }
        }
        imprime_f (F, countF) ;
        printf("\n") ;
    }
    if (countM > 0)
    {
        aux = 0 ;
        for (i = 0 ; i < countM ; i++)
        {
            M.numUSA_M[i] = masculino(M.numM[i]) ;
        }

        for (i = 0 ; i < countM ; i++)
        {
            for (j = i + 1 ; j < countM ; j++)
            {
                if (M.numUSA_M[i] > M.numUSA_M[j])
                {
                    aux = M.numUSA_M[i] ;
                    M.numUSA_M[i] = M.numUSA_M[j] ;
                    M.numUSA_M[j] = aux ;
                }
            }
        }
        imprime_m (M, countM) ;
    }
  return 0 ;
  }