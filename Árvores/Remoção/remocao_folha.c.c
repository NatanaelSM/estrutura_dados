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

No* buscarPai(int valorNo, No *atual, No *pai) {
    if (atual == NULL) {
        return NULL;
    }

    if (valorNo == atual->valor) {
        return pai;
    }else if(valorNo < atual->valor) {
        return buscarPai(valorNo, atual->left_no, atual);
    } else {
        return buscarPai(valorNo, atual->right_no, atual);
    }
}

void removerNo(No **noPai, int valorRemover){

    if (*noPai == NULL){
        printf("Valor não encontrado!\n");
        return NULL;
    }

    if((*noPai) -> left_no -> valor == valorRemover){

        if(isFolha()){
            free((*noPai) -> left_no);
            (*noPai) -> left_no = NULL;
        }else if((*noPai) -> left_no != NULL && (*noPai) -> right_no == NULL){
            
        }else if((*noPai) -> right_no == NULL && (*noPai) -> right_no != NULL){

        }

        if((*noPai) -> left_no == NULL && (*noPai) -> right_no == NULL){
            free((*noPai) -> left_no)
            (*noPai) -> left_no = NULL;
        }

    }else{

    }

}

No* procuraFolha(No **noPai, int valorRemover){

}

No* isLadoNull(No **noPai, int valorRemover){
    if((*noPai) -> left_no != NULL && (*noPai) -> right_no == NULL){
        No* aux = (*ptr) -> left_no;
        while(*aux != NULL){
            aux = aux -> right_no;
        }

        
        
    }else if((*ptr) -> left_no == NULL && (*ptr) -> right_no != NULL){

    }
}



    // if ((*ptr)->left_no == NULL) {
    //     int valor = (*ptr)->valor;
    //     No *aux = *ptr;
    //     *ptr = (*ptr)->right_no;
    //     free(aux);
    //     return valor;
    // }

    // return procurarValorNovoNo(&(*ptr)->left_no);





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
    // printf("\n");
    // remover(buscarNo(691, &raiz));
    // remover(buscarNo(305, &raiz));
    // imprime(raiz);
    No *pai = buscarNo(691, raiz, NULL);
    removerNo(&pai, 691);
    No *pai = buscarNo(305, raiz, NULL);
    removerNo(&pai, 305);

    return 0;
}