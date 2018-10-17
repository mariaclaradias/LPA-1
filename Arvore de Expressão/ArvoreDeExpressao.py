class Pilha:
    def __init__(self):
        self.pilha = []

    def empilha(self, elemento):
        self.pilha.append(elemento)

    def desempilha(self):
        return self.pilha.pop()

    def vazia(self):
        return self.pilha == []

    def topo(self):
         return self.pilha[len(self.pilha)-1]

class No:
    def __init__(self, elemento):
        self.elemento = elemento
        self.noEsq = None
        self.noDir = None

def infixToPostfix(infixexpr):
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    opStack = Pilha()
    postfixList = []
    tokenList = infixexpr.split()

    for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "abcdefghijklmnopqrstuvwxyz" or token in "0123456789":
            postfixList.append(token)
        elif token == '(':
            opStack.empilha(token)
        elif token == ')':
            topToken = opStack.desempilha()
            while topToken != '(':
                postfixList.append(topToken)
                topToken = opStack.desempilha()
        else:
            while (not opStack.vazia()) and \
               (prec[opStack.topo()] >= prec[token]):
                  postfixList.append(opStack.desempilha())
            opStack.empilha(token)

    while not opStack.vazia():
        postfixList.append(opStack.desempilha())
    return " ".join(postfixList)

def printNiveis(rootnode):
    thislevel = [rootnode]
    i = 0
    while thislevel:
        nextlevel = list()
        print("Nivel", i, ": ", end = ' ')
        for n in thislevel:
            print (str(n.elemento), end = ' ')
            if n.noEsq: nextlevel.append(n.noEsq)
            if n.noDir: nextlevel.append(n.noDir)
            thislevel = nextlevel

        i = i + 1
        print(" ")

while True:
    try:
        linha = input()
        postfix = infixToPostfix(linha)

        pilha = Pilha()

        postfix = postfix.replace(" ", "")

        tamString = len(postfix)
        for i in range(0, tamString):
            if postfix[i] == '+' or postfix[i] == '-' or postfix[i] == '*' or postfix[i] == '/':
                noRaiz = No(postfix[i])
                noRaiz.noDir = pilha.desempilha()
                noRaiz.noEsq = pilha.desempilha()

                pilha.empilha(noRaiz)
            else:
                no = No(postfix[i])
                pilha.empilha(no)

        printNiveis(pilha.desempilha())

    except EOFError:
        break
