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

int main() {
    No *raiz = NULL;
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 13);
    raiz = insere(raiz, 17);
    
    return 0;
}