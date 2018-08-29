#include <stdlib.h>
#include <stdio.h>
#define vertex int

struct graph{
    int V;
    int A;
    int **adj;
    int *visited;
};

typedef struct graph *Graph;

static int **MatrixInit(int r, int c, int val){
    int **m = new int*[r];

    for(int i = 0; i < r; i++){
        m[i] = new int[c];
    }

    for(vertex i = 0; i < r; i++){
        for(vertex j = 0; j < c; j++){
            m[i][j] = val;
        }
    }

    return m;
}

Graph GraphInit(int V){
    Graph G = (Graph) malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MatrixInit(V, V, 0);
    G->visited = new int[V];
    for(int i = 0; i < V; i++){
      G->visited[i] = 0;
    }

    return G;
}

void GraphInsertArc(Graph G, vertex v, vertex w, int weight){
    if(G->adj[v][w] == 0){
        G->adj[v][w] = weight;
        G->adj[w][v] = weight;
        G->A++;
    }
}

int count(Graph G, vertex v, int numP){
  int resultado = 0;
  for(int i = 0; i < numP; i++){
    if(G->adj[v][i] == 1 && G->visited[i] == 0){
      G->visited[i] = 1;
      resultado = resultado + 1 + count(G, i, numP);
    }
  }

  return resultado;
}

int main(){
  int numTest;
  scanf("%d\n", &numTest);

  for(int i = 0; i < numTest; i++){
    int numP;
    int numR;

    scanf("%d %d", &numP, &numR);

    Graph G;
    G = GraphInit(numP);

    for(int j = 0; j < numR; j++){
      int friend1, friend2;
      scanf("%d %d", &friend1, &friend2);

      GraphInsertArc(G, friend1 - 1, friend2 - 1, 1);
    }

    int max = 0;
    for(int j = 0; j < numP; j++){
      if(G->visited[j] == 0){
        G->visited[j] = 1;

        int aux = count(G, j, numP);
        if(aux > max){
          max = aux;
        }
      }
    }

    printf("%d\n", max + 1);
  }
}
