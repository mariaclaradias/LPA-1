import networkx as nx
import matplotlib.pyplot as plt

linha = input()

while linha != "0 0 0":

    numEmpresas, numPares, numLigacoes = linha.split(" ")
    numEmpresas = int(numEmpresas)
    numPares = int(numPares)
    numLigacoes = int(numLigacoes)

    G = nx.Graph()

    for i in range(0, numPares):
        linha = input()
        empresa1, empresa2 = linha.split(" ")

        G.add_edge(empresa1, empresa2)

    # nx.draw_networkx(G)
    # plt.show()

    remove = True
    while remove == True:
        aux = G.copy()
        remove = False
        for node in aux.nodes():
            if G.degree(node) < numLigacoes:
               G.remove_node(node)
               remove = True

    if len(G) > 0:
        Gc = max(nx.connected_component_subgraphs(G), key=len)
        print(len(Gc))
    else:
        print("0")

    linha = input()
