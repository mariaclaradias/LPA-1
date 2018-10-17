import networkx as nx
import matplotlib.pyplot as plt

numTestes = int(input())

for i in range(0, numTestes):
    G = nx.Graph()

    numVilas, numCastelos, numRuas, distMax, maxVezes = input().split(" ")
    numVilas =  int(numVilas)
    numCastelos = int(numCastelos)
    numRuas = int(numRuas)
    distMax = int(distMax)
    maxVezes = int(maxVezes)

    for j in range(0, numRuas):
        lugar1, lugar2, distancia = input().split(" ")
        distancia = int(distancia)

        G.add_edge(lugar1, lugar2, weight = distancia)

    castelos = []
    for j in range(0, numVilas + numCastelos):
        if j  < numVilas:
            castelos.append(False)
        else:
            castelos.append(True)

    for node in G.nodes():
        

    nx.set_node_attributes(G, castelos, 'castelos')

    nx.draw_networkx(G)
    plt.show()
