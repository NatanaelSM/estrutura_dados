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

    if (*ptr == NULL) return NULL;

    if(valorDeletar < (*ptr) -> valor){
        (*ptr) -> left_no = remover(&(*ptr) -> left_no, valorDeletar);
    }else if (valorDeletar > (*ptr) -> valor){
        (*ptr) -> right_no = remover(&(*ptr) -> right_no, valorDeletar);
    }else{
        if((*ptr) -> left_no == NULL && (*ptr) -> right_no == NULL){
            free(*ptr);
            return NULL;
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
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 13);
    raiz = insere(raiz, 17);
    raiz = insere(raiz, 1);
    
    imprime(raiz);
    printf("\n");
    remover(&raiz, 1);
    remover(&raiz, 17);
    imprime(raiz);
    
    return 0;
}