#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *decToBin(int valor){
  char *resultado;
  resultado = new char[34];
  strcpy(resultado, "");

  int i = 0;
  while(valor > 0){
    if(valor % 2 == 0){
      strcat(resultado, "0");
    } else{
      strcat(resultado, "1");
    }

    i++;
    valor = valor / 2;
  }

  return resultado;
}

int binToDec(char *texto){
  int resultado = 0;
  int tam = strlen(texto);

  int expoente = 0;
  for(int i = tam - 1; i >= 0; i--){
    if(texto[i] == '1'){
      resultado = resultado + pow(2, expoente);
    }

    expoente++;
  }

  return resultado;
}

int hexToDec(char *texto){
  int resultado = 0;
  int tam = strlen(texto);

  int expoente = 0;
  for(int i = tam - 1; i >= 0; i--){
    switch(texto[i]){
      case '1':
        resultado = resultado + 1*(pow(16, expoente));
        break;
      case '2':
        resultado = resultado + 2*(pow(16, expoente));
        break;
      case '3':
        resultado = resultado + 3*(pow(16, expoente));
        break;
      case '4':
        resultado = resultado + 4*(pow(16, expoente));
        break;
      case '5':
        resultado = resultado + 5*(pow(16, expoente));
        break;
      case '6':
        resultado = resultado + 6*(pow(16, expoente));
        break;
      case '7':
        resultado = resultado + 7*(pow(16, expoente));
        break;
      case '8':
        resultado = resultado + 8*(pow(16, expoente));
        break;
      case '9':
        resultado = resultado + 9*(pow(16, expoente));
        break;
      case 'a':
        resultado = resultado + 10*(pow(16, expoente));
        break;
      case 'b':
        resultado = resultado + 11*(pow(16, expoente));
        break;
      case 'c':
        resultado = resultado + 12*(pow(16, expoente));
        break;
      case 'd':
        resultado = resultado + 13*(pow(16, expoente));
        break;
      case 'e':
        resultado = resultado + 14*(pow(16, expoente));
        break;
      case 'f':
        resultado = resultado + 15*(pow(16, expoente));
        break;
    }
    expoente++;
  }

  return resultado;
}

char *decToHex(int valor){
  char *resultado;
  resultado = new char[9];

  int i = 0;
  while(valor > 0){
    switch(valor % 16){
      case 0:
        strcat(resultado, "0");
        break;
      case 1:
        strcat(resultado, "1");
        break;
      case 2:
        strcat(resultado, "2");
        break;
      case 3:
        strcat(resultado, "3");
        break;
      case 4:
        strcat(resultado, "4");
        break;
      case 5:
        strcat(resultado, "5");
        break;
      case 6:
        strcat(resultado, "6");
        break;
      case 7:
        strcat(resultado, "7");
        break;
      case 8:
        strcat(resultado, "8");
        break;
      case 9:
        strcat(resultado, "9");;
        break;
      case 10:
        strcat(resultado, "a");;
        break;
      case 11:
        strcat(resultado, "b");;
        break;
      case 12:
        strcat(resultado, "c");;
        break;
      case 13:
        strcat(resultado, "d");;
        break;
      case 14:
        strcat(resultado, "e");;
        break;
      case 15:
        strcat(resultado, "f");;
        break;
    }

    i++;
    valor = valor / 16;
  }

  return resultado;
}

int main(){
  int numTestes;
  scanf("%d", &numTestes);

  for(int i = 0; i < numTestes; i++){
    char texto[32];
    char tipo[3];

    scanf("%s %s", texto, tipo);

    if(strcmp(tipo, "bin") == 0){
      int valorDecimal = binToDec(texto);
      char *valorHexa = decToHex(valorDecimal);

      printf("%d dec\n", valorDecimal);
      printf("%s hex\n\n", valorHexa);
    }else if(strcmp(tipo, "dec") == 0){
      char *valorBin = decToBin(atoi(texto));
      char *valorHexa = decToHex(atoi(texto));

      int tam2 = strlen(valorHexa);
      for(int j = tam2 - 1; j >= 0; j--){
        printf("%c", valorHexa[j]);
      }
      printf(" hex\n");

      int tam = strlen(valorBin);
      for(int j = tam - 1; j >= 0; j--){
        printf("%c", valorBin[j]);
      }
      printf(" bin\n\n");
    }else{
      int valorDec = hexToDec(texto);
      char *valorBin = decToBin(valorDec);

      printf("%d dec\n", valorDec);

      int tam = strlen(valorBin);
      for(int j = tam - 1; j >= 0; j--){
        printf("%c", valorBin[j]);
      }
      printf(" bin\n\n");
    }
  }
}
