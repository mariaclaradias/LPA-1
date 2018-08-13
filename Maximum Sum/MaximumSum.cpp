#include <stdio.h>
#include <stdlib.h>

int** newMatriz(int tam){
  int **matriz = new int*[tam];
  for(int i = 0; i < tam; i++){
    matriz[i] = new int[tam];
  }

  return matriz;
}

int main(){
  int tam;
  scanf("%d", &tam);

  int **matriz;
  matriz = newMatriz(tam);

  for(int i = 0; i < tam; i++){                 //Inicialização da matriz
    for(int j = 0; j < tam; j++){
      scanf("%d", &matriz[i][j]);
    }
  }

  int sum = -999999;
  for(int li = 0; li < tam; li++){              //Linha inicial do retangulo
    for(int lf = li; lf < tam; lf++){           //Linha final do retangulo
      for(int ci = 0; ci < tam; ci++){          //Coluna inicial do retangulo
        for(int cf = ci; cf < tam; cf++){       //Coluna final do retangulo
          int aux = 0;

          for(int i = li; i <= lf; i++){        //Percorrer retangulo formado e achar a soma dos elementos
            for(int j = ci; j <= cf; j++){
                aux = aux + matriz[i][j];
            }
          }

          if(aux > sum){
            sum = aux;
          }
        }
      }
    }
  }

  printf("%d\n", sum);
}
