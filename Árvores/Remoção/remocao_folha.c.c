#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *left_no;
    struct No *right_no;
} No;

No* insere(No *ptr, int valorInserir) {
    if (ptr == NULL) {
        No *novoNo = malloc(sizeof(No));
        novoNo->valor = valorInserir;
        novoNo->left_no = NULL;
        novoNo->right_no = NULL;
        return novoNo;
    }
    if (valorInserir < ptr->valor) {
        ptr->left_no = insere(ptr->left_no, valorInserir);
    } else if (valorInserir > ptr->valor) {
        ptr->right_no = insere(ptr->right_no, valorInserir);
    }
    return ptr;
}


No* remover(No **ptr, int valorDeletar){

    if (*ptr == NULL){
        printf("Valor não encontrado!\n");
        return NULL;
    }

    if(valorDeletar < (*ptr) -> valor){
        (*ptr) -> left_no = remover(&(*ptr) -> left_no, valorDeletar);
    }else if (valorDeletar > (*ptr) -> valor){
        (*ptr) -> right_no = remover(&(*ptr) -> right_no, valorDeletar);
    }else{
        if((*ptr) -> left_no == NULL && (*ptr) -> right_no == NULL){
            free(*ptr);
            return NULL;
        }else if((*ptr) -> left_no != NULL && (*ptr) -> right_no == NULL){
            No *aux = (*ptr) -> left_no;
            free(*ptr);
            return aux;
        }else if((*ptr) -> left_no == NULL && (*ptr) -> right_no != NULL){
            No *aux = (*ptr) -> right_no;
            free(*ptr);
            return aux;
        }
    }

    return *ptr;
}


void imprime(No *raiz){
    if(raiz !=NULL){
        imprime(raiz -> left_no);
        printf("%d ", raiz -> valor);
        imprime(raiz -> right_no);
    }
}

int main() {
    No *raiz = NULL;
    raiz = insere(raiz, 500);
    raiz = insere(raiz, 250);
    raiz = insere(raiz, 750);
    raiz = insere(raiz, 175);
    raiz = insere(raiz, 305);
    raiz = insere(raiz, 75);
    raiz = insere(raiz, 275);
    raiz = insere(raiz, 432);
    raiz = insere(raiz, 630);
    raiz = insere(raiz, 1200);
    raiz = insere(raiz, 691);
    raiz = insere(raiz, 1355);
    
    imprime(raiz);
    printf("\n");
    remover(&raiz, 175);
    remover(&raiz, 630);
    remover(&raiz, 1200);
    imprime(raiz);
    
    return 0;
}