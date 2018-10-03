import networkx as nx
import matplotlib.pyplot as plt

numCartas = input()
numCartas = int(numCartas)

cartas = []
cartas = input().split(" ")

G = nx.Graph()

for i in range(0, numCartas - 1):
    carta1, carta2 = input().split(" ")


    G.add_edge(int(carta1), int(carta2))

pontos = 0
for i in range(1, int(numCartas/2) + 1):
    posicao1 = 0
    posicao2 = 0

    aux = 0
    for j in range(0, numCartas):
        if(cartas[j] == str(i)):
            if aux == 0:
                posicao1 = j + 1
                aux = aux + 1
            else:
                posicao2 = j + 1
                aux = aux + 1
                j = numCartas

    path = nx.shortest_path(G, source = posicao1, target = posicao2)
    tamPath = len(path)
    # if(tamPath > max):
    #     max = tamPath
    pontos = pontos + (tamPath - 1)


print(pontos)


# nx.draw_networkx(G)
# plt.show()
