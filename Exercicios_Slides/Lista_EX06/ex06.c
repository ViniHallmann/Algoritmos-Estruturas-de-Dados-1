/*Implementar em C um programa que utilize uma matriz com vetor de ponteiros e que ofereça as seguintes opções parao usuário:
)Criar eredimencionaruma matriz m x n, onde n e m são fornecidos pelo usuário;
2) Realizar a leitura dos elementos da matriz;
3) Fornecer a soma dos elementos da matriz;
4) Retornar em um vetor (utilizando ponteiros) os elementos de uma determinada coluna da matriz;
5) Imprimir a matriz6) Sair do programaObservações:
1) A matriz deve ser alocada dinamicamente no programa por meio do uso da funçãomalloc.
2) O programa deve ser modularizado e utilizar os seguintes protótipos desubalgoritmos:
a.int**criaMatriz(intm,intn)
b.voidleiaMatriz(int**mat,intm,intn)
c.intsomaMatriz(int**mat,intm,intn) }
d.int*colunaMatriz(int**mat,intm,intn,intncoluna)
e.voidliberaMatriz(int**mat,intncoluna)
f.voidimprimeMatriz(int**mat,intm,intn)
g.voidimprimeVetor(int*vet,intn) { }
3) Osubalgoritmoint*colunaMatriz(int**mat,intm,intn,intncoluna) deve criar um novo vetor (ponteiro paravetor) e retornar o mesmo para o programa principal que será responsável pela impressão dos valores a partirda chamada devoidimprimeVet(int*vet,intn) {}*/