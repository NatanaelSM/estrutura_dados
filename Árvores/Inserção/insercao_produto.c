#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int codigo;
    double valor;
    char nome[256];
    struct No *left_no;
    struct No *right_no;
} Produto;

void imprimirArvore(Produto *raiz){
    if(raiz != NULL){
        imprimirArvore(raiz -> left_no);
        printf("%d ", raiz ->codigo);
        imprimirArvore(raiz-> right_no);
    }
}

// Produto* inserirProduto(Produto **ptr, int codigoProduto, double valorProduto, char nomeProduto[]) {
    
//     if(*ptr == NULL){
//         Produto *novoProduto = malloc(sizeof(Produto));
//         novoProduto -> codigo = codigoProduto;
//         novoProduto -> valor = valorProduto;
//         strcpy(novoProduto->nome, nomeProduto);
//         novoProduto->left_no = NULL;
//         novoProduto->right_no = NULL;
//         *ptr = novoProduto;
//     }
//     if(codigoProduto < (*ptr) -> codigo){
//         (*ptr) -> left_no = inserirProduto(&(*ptr) -> left_no, codigoProduto, valorProduto, nomeProduto);
//     }
//     if(codigoProduto > (*ptr) -> codigo){
//         (*ptr) -> right_no = inserirProduto(&(*ptr) -> right_no, codigoProduto, valorProduto, nomeProduto);
//     }

//     return *ptr;
// };

void inserirProduto(Produto **ptr, int codigoProduto, double valorProduto, char nomeProduto[]) {
    
    if(*ptr == NULL){
        Produto *novoProduto = malloc(sizeof(Produto));
        novoProduto -> codigo = codigoProduto;
        novoProduto -> valor = valorProduto;
        strcpy(novoProduto->nome, nomeProduto);
        novoProduto->left_no = NULL;
        novoProduto->right_no = NULL;
        *ptr = novoProduto;
    } else if(codigoProduto < (*ptr) -> codigo){
        inserirProduto(&(*ptr) -> left_no, codigoProduto, valorProduto, nomeProduto);
    } else if(codigoProduto > (*ptr) -> codigo){
        inserirProduto(&(*ptr) -> right_no, codigoProduto, valorProduto, nomeProduto);
    }

};

void escolherAcao(Produto **raiz){
    int numAcao = -1;

    while(numAcao != 0){

        printf("Digite um dos valores a seguir para realizar uma ação:\n1 - Adicionar produto\n0 - Sair\n");
        scanf("%d", &numAcao);

        switch(numAcao){
            case 1:
                int codigoProduto;
                double valorProduto;
                char nomeProduto[256];

                printf("Digite o código do produto:\n");
                scanf("%d", &codigoProduto);

                printf("Digite o valor do produto:\n");
                scanf("%lf", &valorProduto);

                printf("Digite o nome do produto:\n");
                scanf(" %[^\n]", nomeProduto);

                inserirProduto(raiz, codigoProduto, valorProduto, nomeProduto);

                break;
            case 0:
                printf("Programa finalizado!\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;

        };
    };
}

int main() {
    
    Produto *raiz = NULL;
    escolherAcao(&raiz);
    imprimirArvore(raiz);
    
    return 0;
}