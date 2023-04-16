//Árvore com todos os conceitos vistos até agora

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Estrutura da árvore
struct Arvore {
    int numero;
    struct Arvore *esquerda, * direita;
}; typedef struct Arvore NoArvore;

//Chamada das funções
int Menu ();
NoArvore *InserirNumero   ( NoArvore *raiz, int numero );
NoArvore *RemoverNumero   ( NoArvore *raiz, int numero );
NoArvore *LimparArvore    ( NoArvore *raiz );
int QuantidaDeFolhas      ( NoArvore *raiz );
int QuantidaDeNos         ( NoArvore *raiz );
int AlturaDaArvore        ( NoArvore *raiz );
void InformacoesDaArvore  ( NoArvore *raiz );
void ImprimirArvore       ( NoArvore *raiz );
bool VerificaArvoreVazia  ( NoArvore *raiz );
bool BuscarNaArvore       ( NoArvore *raiz, int numero );
int main (){
    int opcao, numero;
    NoArvore *arvore = NULL;
    for (;;){
        opcao = Menu();
        switch (opcao) {
        case 1:
            printf( " Digite o numero que deseja inserir na árvore: ");
            scanf( "%d", &numero );
            arvore = InserirNumero( arvore, numero );
            break;
        case 2:
            printf( " Digite o numero que deseja remover da árvore: ");
            scanf( "%d", &numero );
            arvore = RemoverNumero ( arvore, numero );
            break;
        case 3:
            printf( " Digite o numero que deseja inserir na árvore: ");
            scanf( "%d", &numero );
            if ( BuscarNaArvore ( arvore, numero ) ){
                printf ( "\n Valor encontrado %d na raiz\n", numero );
            } else {
                printf ( "\n Valor %d não encontrado na raiz\n", numero);
            }
            break;
        case 4:
            InformacoesDaArvore ( arvore );
            break;
        case 5:
            printf ( "\n" );
            ImprimirArvore ( arvore );
            printf ( "\n" );
            break;
        case 6:
            arvore = LimparArvore ( arvore );
            break;
        case 7:
            exit(0);
            break;
        default:
            printf ( "Erro!!! Tente novamente..." );
        }
    }
    
}

int Menu (){
    int opcao;
    do {
        printf ( "--------------MENU--------------" );
        printf ( "\n (1) Inserir um número na árvore \n (2) Remover um número da árvore \n (3) Buscar um número na árvore \n (4) Ver informações da árvore \n (5) Imprimir árvore \n (6) Limpar árvore\n (7) Sair do programa \n Digite a opção do programa: ");
        scanf ( "%d", &opcao );
        getchar ();
    } while ( opcao <= 0 || opcao > 7 );
    return opcao;
}

NoArvore *InserirNumero ( NoArvore *raiz, int numero ){
    if ( raiz == NULL ){ //Se for o primeiro valor, ele já coloca esse valor na raiz
        raiz = malloc ( sizeof ( NoArvore ) );
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else {
        if ( numero < raiz -> numero ){ //Se o valor do numero for menor que o valor na raiz, vai colocar ele na esquerda
            raiz -> esquerda = InserirNumero ( raiz -> esquerda, numero ); // Percorre pela esquerda até achar NULL para colocar ele na menor posicão possivel
        } else {                                                          //        OU
            raiz -> direita = InserirNumero ( raiz -> direita, numero ); // Se o valor do numero for maior que o valor na raiz, vai colocar ele na direita, tanto na comparação do InserirNumero na esquerda e na comparação direta
        }
        return raiz;
    }
}

NoArvore *RemoverNumero ( NoArvore *raiz, int numero ){
    if ( raiz == NULL ){
        printf ( "Valor não encontrado...");
        return NULL;
    } else {
        if ( raiz -> numero == numero ){
            // REMOÇÃO SEM FILHO
            if ( raiz -> esquerda == NULL && raiz -> direita == NULL ){ //Se não ter filho, só remove o nodo
                free ( raiz );
                return NULL;
            }
            //REMOÇÃO COM DOIS FILHOS
            if ( raiz -> esquerda != NULL && raiz -> direita != NULL ){
                NoArvore *noAuxiliar;
                noAuxiliar = raiz -> esquerda; // O nó auxiliar recebe o nodo que eu quero remover
                while ( noAuxiliar -> direita != NULL ){ // eu percorro pela direita até achar o mais valor entre os filhos do nó raiz;
                    noAuxiliar = noAuxiliar -> direita;
                }
                raiz -> numero = noAuxiliar -> numero; // aqui eu troco o valor da raiz pelo maior valor dos filhos
                noAuxiliar -> numero = numero; //Eu faço essa troca pois assim o valor que eu quero remover vai virar uma folha e dai no proximo laço ele cai no primeiro if dessa função ( REMOÇÃO SEM FILHO )
                raiz -> esquerda = RemoverNumero ( raiz -> esquerda, numero ); // Aqui eu removo a raiz que foi trocada percorrendo somente o lado esquerdo, que foi o que eu defini na hora da troca dos valores
                return raiz;
            }
            //REMOÇÃO COM UM FILHO
            if ( raiz -> esquerda != NULL && raiz -> direita == NULL ){ // Se o nó tiver somente um filho 
                NoArvore *noAuxiliar; 
                noAuxiliar = raiz -> esquerda; // Eu armazeno o valor do filho a esquerda da raiz no aux e depois do um free na raiz
                free ( raiz );
                return noAuxiliar;
            } else if ( raiz -> esquerda == NULL && raiz -> direita != NULL ){ // OU eu armazeno o valor do filho a direita da raiz no aux e depois do um free na raiz
                NoArvore *noAuxiliar;
                noAuxiliar = raiz -> direita;
                free ( raiz );
                return noAuxiliar;
            }
        }
        else { // Essa parte do código serve para percorrer a árvore até achar o valor que deseja remover
            if ( numero < raiz -> numero ){
                raiz -> esquerda = RemoverNumero ( raiz -> esquerda, numero );
            } else {
                raiz -> direita = RemoverNumero ( raiz -> direita, numero );
            }
            return raiz;
        }
    }
}

bool BuscarNaArvore ( NoArvore *raiz, int numero ){
    if ( raiz != NULL ){
        if ( numero == raiz -> numero ){ //Se o numero for igual ao numero na arvore retorna verdadeiro 
            return true; 
        } else if ( numero < raiz -> numero ){ // Essa parte do código só percorre a árvore procurando pelo numero
            return BuscarNaArvore ( raiz -> esquerda, numero );
        } else {
        return BuscarNaArvore ( raiz -> direita, numero );
        }   
    } else {
        return false;
    }
    
}

void ImprimirArvore ( NoArvore *raiz ){
    if ( raiz != NULL ){
        printf ( " %d ", raiz -> numero);
        ImprimirArvore ( raiz -> esquerda );
        ImprimirArvore ( raiz -> direita );
    }
}

int QuantidaDeFolhas ( NoArvore *raiz ){
    if ( raiz == NULL ){
        return 0;
    } else if ( raiz -> esquerda == NULL && raiz -> direita == NULL){ //Isso aqui verifica se o nodo é uma folha, a função faz isso vendo se dois lados do nodo são nulos, se sim, soma mais 1
        return 1;
    } else {
        int quantidadeDeFolhasEsquerda = QuantidaDeFolhas ( raiz -> esquerda ), quantidadeDeFolhasDireita = QuantidaDeFolhas ( raiz -> direita );
        return quantidadeDeFolhasDireita + quantidadeDeFolhasDireita;
    }
}

int QuantidaDeNos ( NoArvore *raiz ){
    if ( raiz == NULL ){
        return 0;
    } else {
        int quantidadeDeNosEsquerda = QuantidaDeNos ( raiz -> esquerda ), quantidadeDeNosDireita = QuantidaDeNos ( raiz -> direita );
        return quantidadeDeNosDireita + quantidadeDeNosDireita + 1;
    }
}

int AlturaDaArvore ( NoArvore *raiz ){
    if ( VerificaArvoreVazia ( raiz ) == true )
        printf ( "\n Arvore vazia!");
        return 0;
    if ( raiz == NULL ){
        return -1;
    } else {
        int alturaEsquerda = AlturaDaArvore( raiz -> esquerda ), alturaDireita = AlturaDaArvore( raiz -> direita );
        if ( alturaEsquerda > alturaDireita ){
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}

void InformacoesDaArvore ( NoArvore *raiz ){
    printf ( "-----------INFORMACOES----------" );
    printf ( "\n Altura da arvore: %d ", AlturaDaArvore ( raiz ) );
    printf ( "\n Quantidade de folhas na arvore: %d ", QuantidaDeFolhas ( raiz ) );
    printf ( "\n Quantidade de nos na arvore: %d \n", QuantidaDeNos ( raiz ) );
}

bool VerificaArvoreVazia ( NoArvore *raiz ){
    if ( raiz == NULL )
        return true;
    else 
        return false;
}

NoArvore *LimparArvore ( NoArvore *raiz ){
    if ( raiz != NULL ){
        raiz -> esquerda = LimparArvore ( raiz -> esquerda );
        raiz -> direita = LimparArvore ( raiz -> direita );
        free ( raiz );
        return NULL;
    }
}