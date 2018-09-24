import networkx as nx
import matplotlib.pyplot as plt

linha = input()

while linha != "0 0":

    numJuncoes, numEstradas = linha.split(" ")
    numJuncoes = int(numJuncoes)
    numEstradas = int(numEstradas)

    G = nx.Graph()

    for i in range(0, numEstradas):
        linha = input()
        juncao1, juncao2, distancia = linha.split(" ")
        distancia = int(distancia)

        G.add_edge(juncao1, juncao2, weight = distancia)

    T = nx.minimum_spanning_tree(G)

    distTotal = 0
    for (u, v, peso) in G.edges.data('weight'):
        distTotal = distTotal + peso

    distArvore = 0
    for (u, v, peso) in T.edges.data('weight'):
        distArvore = distArvore + peso

    print(distTotal - distArvore)


    linha = input()


# nx.draw_networkx(G)
# plt.show()
# nx.draw_networkx(T)
# plt.show()
