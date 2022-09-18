#include <stdio.h>
#include <math.h>

typedef struct{
  int numM[100] ;
  int qtdM[100] ; 
  double numUSA_M[100] ;
}SapatoM ;

typedef struct{
  int numF[100] ;
  int qtdF[100] ;
  double numUSA_F[100] ;
}SapatoF ;

float feminino(float a){
  float converte = ((((a * 6.67) + 19)/25.4) * 3) - 23 ;
  float f = ceil(converte) ;
  f = f - converte ;
  if (f >= 0.0 && f <= 0.20){    //se vd > 0,8
      return ceil(converte) ;
  }else
  if (f > 0.21 && f <= 0.6){    //se 0,4 <= vd < 0,8
      return round(converte) + 0.5 ;
  }else
  if (f > 0.61 && f <= 1){    //se 0 <= vd < 0,4
       return round(converte) ;
  }
}

float masculino(int b){
  float converte = ((((b * 6.67) + 19)/25.4) * 3) - 24 ;
  float m = ceil(converte) ;
  m = m - converte ;
  if (m >= 0.0 && m <= 0.20){    //se vd > 0,8
      printf("M %.2lf\n", converte) ;
      return ceil(converte) ;
  }else
  if (m > 0.21 && m <= 0.6){    //se 0,4 <= vd < 0,8
      return floor(converte) + 0.5 ;
  }else
  if (m > 0.61 && m <= 1){    //se 0 <= vd < 0,4
       return floor(converte) ;
  }
}

int main(void) {
  SapatoM lista_M ;
  SapatoF lista_F ;
  
  int l[7] = {3,35,1,40,1,40,1} ;
  int i, j, test = l[0], countF = 0, countM = 0 ;
  
  for (j = 0, i = 2 ; j < 7, i < 7 ; j++, i += 2){
    if (l[i] == 1){
        lista_F.numF[j] = l[i-1] ;
        lista_F.numUSA_F[j] = feminino(lista_F.numF[j]) ;
        lista_F.qtdF[j] = 1 ;
        countF += 1 ;
    }else
    if (l[i] == 0){
        lista_M.numM[j] = l[i-1] ;
        lista_M.numUSA_M[j] = masculino(lista_M.numM[j]) ;
        lista_M.qtdM[j] = 1 ;
        countM += 1 ;
    }
  }
  if (countF > 0){
      printf ("F ") ;
  }
  for (i = 0 ; i < countF ; i++)
  {
      printf ("%.1f-(%d) ", lista_F.numUSA_F[i], lista_F.qtdF[i]) ;
  }
  if (countM > 0){
      printf ("M ") ;
  }
  for (i = 0 ; i < countM ; i++)
  {
      printf ("%.1f-(%d)\n ", lista_M.numUSA_M[i], lista_M.qtdM[i]) ;
  }
  
  return 0 ;
}
