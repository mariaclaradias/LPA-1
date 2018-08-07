#include <stdio.h>

int main(void) {
  int tam;
  scanf("%d", &tam);

  //Criar matriz
  //Ler dados

  int matriz[4][4] = {0, -2, -7, 0, 9, 2, -6, 2, -4, 1, -4, 1, -1, 8, 0, -2};

  int sum = -99999;
  for(int i = 0; i < tam; i++){
    for(int iniLinha = 0; iniLinha < tam - i; iniLinha++){
      for(int j = 0; j < tam; j++){
        for(int iniColuna = 0; iniColuna < tam - j; iniColuna++){
          int aux = 0;
          for(int k = iniLinha; k <= i; k++){
            for(int l = iniColuna; l <= j; l++){
              aux = aux + matriz[k][l];
            }
          }
          if(sum < aux){
            sum = aux;
          }
        }
      }
    }
  }

  printf("%d", sum);

  printf("")
  printf("")
  printf("")
  printf("")
  

  return 0;
}
