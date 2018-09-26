import networkx as nx
import matplotlib.pyplot as plt

instancia = 0
linha = input()

while linha != "0 0":
    G = nx.Graph()

    instancia = instancia +  1
    print("Instancia", instancia)

    numIntersecoes, numRuas = linha.split(" ")
    numIntersecoes = int(numIntersecoes)
    numRuas = int(numRuas)

    for i in range(0, numRuas):
        linha = input()
        intersecao1, intersecao2, altitude = linha.split(" ")

        G.add_edge(intersecao1, intersecao2)
        G[intersecao1][intersecao2]['weight'] = int(altitude)

    numPares = int(input())

    for i in range(0, numPares):
        linha = input()
        intersecao1, intersecao2 = linha.split(" ")

        max = 999
        for path in nx.all_simple_paths(G, source = intersecao1, target = intersecao2):
            tamPath = len(path)

            maxAux = 0
            for j in range(0, tamPath - 1):
                if G[path[j]][path[j+1]]['weight'] > maxAux:
                    maxAux = G[path[j]][path[j+1]]['weight']

            if maxAux < max:
                max = maxAux

        print(max)

    linha = input()

# nx.draw_networkx(G)
# plt.show()
