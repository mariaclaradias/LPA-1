#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* checker(char fraseCompleta[40], char fraseAuxiliar[40], char resultado[40], char **dicionario, int i){
  printf("%s\n", fraseCompleta);
  for(int j = i; j< 2000 && strcmp(dicionario[j], "") != 0; j++){
    bool flag = true;
    for(int k = 0; k < 20 && dicionario[j][k] != '\0' && flag == true; k++){
      int l = 0;
      for(l = 0; l < 40 && fraseAuxiliar[l] != '\0'; l++){
        // printf("comparando %c com %c: ", dicionario[j][k], fraseAuxiliar[l]);
        if(dicionario[j][k] == fraseAuxiliar[l]){
          fraseAuxiliar[l] = ' ';
          l = 40;
        }
      }

      if(l != 41){
        flag = false;
      }
    }

    if(flag == true){
      printf("\tconcatenando %s a %s\n", dicionario[j], resultado);
      char aux[20];
      strcpy(aux, dicionario[j]);
      aux[strlen(dicionario[j]) - 1] = '\0';
      strcat(resultado, aux);
      int tam1 = strlen(fraseCompleta);
      int tam2 = strlen(resultado);

      if(tam1 - 1 == tam2){
        printf("%s = %s\n", fraseCompleta, resultado);
        return NULL;
      }else{
        char novaFraseAuxiliar[40];
        strcpy(novaFraseAuxiliar, fraseAuxiliar);
        char novoResultado[40];
        strcpy(novoResultado, resultado);

        checker(fraseCompleta, novaFraseAuxiliar, novoResultado, dicionario, j + 1);
      }
    }else{
      return NULL;
    }
  }

  return NULL;
}

char** novoDicionario1(char **dicionario, char frase[40]){
  char **novoDicionario = new char*[2000];
  char straux[40];
  for(int i = 0; i < 2000; i++){
    novoDicionario[i] = new char[20];
  }

  int i = 0;
  int aux = 0;
  while(strcmp(dicionario[i], "") != 0){
    bool flag = true;
    strcpy(straux, frase);
    for(int j = 0; j < 20 && dicionario[i][j] != '\0' && flag == true; j++){
      int k = 0;
      for(k = 0; k < 40 && frase[k] != '\0'; k++){
        if(dicionario[i][j] == straux[k]){
          straux[k] = ' ';
          k = 40;
        }
      }

      if(k != 41){
        flag = false;
      }
    }

    if(flag == true){
      strcpy(novoDicionario[aux], dicionario[i]);
      aux++;
    }

    i++;
  }

  return novoDicionario;
}

char** novoDicionario2(char **dicionario, char frase[40]){
  char **novoDicionario = new char*[2000];
  for(int i = 0; i < 2000; i++){
    novoDicionario[i] = new char[20];
  }

  int i = 0;
  int aux = 0;
  while(strcmp(dicionario[i], "") != 0){
    if(strstr(frase, dicionario[i]) == NULL){
      strcpy(novoDicionario[aux], dicionario[i]);
      aux++;
    }

    i++;
  }

  return novoDicionario;
}

char** novoDicionario(char **dicionario, char frase[40]){
  return novoDicionario2(novoDicionario1(dicionario, frase), frase);
}

int main(){
  char **dicionario = new char*[2000];
  for(int i = 0; i < 2000; i++){
    dicionario[i] = new char[20];
  }

  char input[40];
  scanf("%s", input);

  int i = 0;
  while(strcmp(input, "#") != 0){
    strcpy(dicionario[i], " ");
    strcat(dicionario[i], input);
    strcat(dicionario[i], " ");
    i++;
    scanf("%s", input);
  }

  fgets(input, 40, stdin);
  fgets(input, 40, stdin);
  while(strcmp(input, "#\n") != 0){
    char frase[40];
    input[strlen(input) - 1] = ' ';
    strcpy(frase, " ");
    strcat(frase, input);
    char **novoDic = novoDicionario(dicionario, frase);

    char resultado[40];
    strcpy(resultado, "");

    char fraseAuxiliar[40];
    strcpy(fraseAuxiliar, frase);
    checker(frase, fraseAuxiliar, resultado, novoDic, 0);

    fgets(input, 40, stdin);
  }
}

//Lixo

// for(int i = 0; i < 2000 && strcmp(novoDic[i], "") != 0; i++){
//   printf("%s\n", novoDic[i]);
// }

// for(int i = 0; i < 20 && strcmp(dicionario[i], "") != 0; i++){
//   printf("%s\n", dicionario[i]);
// }

// printf("%s %s\n", dicionario[i], frase);
// printf(".%s\n", strstr(frase, dicionario[i]));

// printf(".\n");

// printf("falso\n");
// printf("verdadeiro\n");

// printf("comparando %c com %c: ", dicionario[i][j], frase[k]);

// printf("Na frase %s copiando %s para novo dicionario\n", frase, dicionario[i]);
