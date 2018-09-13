#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool compare(char *word1, char *word2){
  int tam = strlen(word1);

  if(word1[tam - 1] == word2[0]){
    return true;
  }

  return false;
}

bool function(char **words, int numWords, int *verifica, int i){
  bool flag = true;
  bool resultado = false;

  verifica[i] = 1;

  for(int j = 0; j < numWords; j++){
    if(verifica[j] != 1){
      flag = false;
    }
  }

  if(flag == true){
    resultado = true;
  }else{
    for(int j = 0; j < numWords && resultado == false; j++){
      if(!(j == i || verifica[j] == 1)){
        if(compare(words[i], words[j])){
          resultado = function(words, numWords, verifica, j);
        }
      }
    }
  }

  if(resultado == false){
    verifica[i] = 0;
  }

  return resultado;
}

int main(){
  int numTest;

  scanf("%d", &numTest);

  for(int i = 0; i < numTest; i++){
    int numWords;
    scanf("%d", &numWords);


    char **words;
    words = new char*[numWords];
    for(int j = 0; j < numWords; j++){
      words[j] = new char[1000];
    }


    for(int j = 0; j < numWords; j++){
      scanf("%s", words[j]);
    }

    int verifica[numWords];
    for(int j = 0; j < numWords; j++){
      verifica[j] = 0;
    }

    bool resultado = false;
    for(int j = 0; j < numWords && resultado == false; j++){
      if(function(words, numWords, verifica, j) == true){
        resultado = true;
      }
    }

    if(resultado == true){
      printf("Ordering is possible.\n");
    }else{
      printf("The door cannot be opened.\n");
    }
  }
}
