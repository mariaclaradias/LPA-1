#include <stdio.h>
#include <stdlib.h>

struct graph{
  int numArestas;
  int **matriz;
  int *visitado;
};
typedef struct graph *Graph;

int **newMatriz(int n){
  int **matriz = new int*[n];

  for(int i = 0; i < n; i++){
    matriz[i] = new int[n];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matriz[i][j] = 0;
    }
  }

  return matriz;
}

Graph newGraph(int n){
  Graph G = (Graph) malloc(sizeof *G);

  G->numArestas = 0;
  G->matriz = newMatriz(n);
  G->visitado = new int[n];

  for(int i = 0; i < n; i++){
    G->visitado[i] = 0;
  }

  return G;
}

void inserirAresta(Graph G, int v, int w){
  G->matriz[v][w] = 1;
  G->matriz[w][v] = 1;
}

int function(Graph G, int inicio, int fim){
  int resp = 1;
  G->visitado[inicio] = 1;

  for(int i = 0; i < fim; i++){
    if(i != inicio && G->matriz[inicio][i] == 1 && G->visitado[i] == 0){
      resp = resp + function(G, i, fim);
    }
  }

  return resp;
}

int main(){
  int numTestes;
  scanf("%d", &numTestes);

  for(int i = 0; i < numTestes; i++){
    int numPessoas, numRelacoes;
    scanf("%d %d", &numPessoas, &numRelacoes);

    Graph G = newGraph(numPessoas);
    for(int j = 0; j < numRelacoes; j++){
      int amigo1, amigo2;
      scanf("%d %d", &amigo1, &amigo2);

      inserirAresta(G, amigo1 - 1, amigo2 - 1);
    }

    int maior = 0;

    for(int j = 0; j < numPessoas; j++){
      int resp = function(G, j, numPessoas);

      if(resp > maior){
        maior = resp;
      }
    }
    printf("%d\n", maior);
  }
}
