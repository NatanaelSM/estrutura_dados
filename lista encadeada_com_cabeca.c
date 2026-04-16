#include <stdio.h>
#include <stdlib.h>

// Lista encadeada com cabeça

typedef struct No {
    int valor;
    struct No *ptrProxNo;
} No;

void inserirInicio(No *cabecaLista, int valorNovoNo){

    No *ptrAtual = cabecaLista;
    No *novoNo = malloc(sizeof(No));

    if (novoNo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoNo->valor = valorNovoNo;
    novoNo->ptrProxNo = ptrAtual -> ptrProxNo;

    ptrAtual->ptrProxNo = novoNo;
}

void inserirFim(No *cabecaLista, int valorNovoNo){
    No *ptrAtual = cabecaLista;
    No *novoNo = malloc(sizeof(No));

    if (novoNo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoNo->valor = valorNovoNo;
    novoNo->ptrProxNo = NULL;

    while(ptrAtual->ptrProxNo != NULL){
        ptrAtual = ptrAtual->ptrProxNo;
    }

    ptrAtual->ptrProxNo = novoNo;
}

void inserirMeio(No *cabecaLista, int valorNovoNo, int pos){
    No *ptrAtual = cabecaLista -> ptrProxNo;
    No *novoNo = malloc(sizeof(No));
    int posAtual = 0;

    if (novoNo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoNo->valor = valorNovoNo;

    while(posAtual != pos - 1){
        if (ptrAtual == NULL){
            printf("Posicao invalida!\n");
            return;
        }
        ptrAtual = ptrAtual -> ptrProxNo;   
        posAtual++;
    }

    novoNo -> ptrProxNo = ptrAtual -> ptrProxNo;
    ptrAtual -> ptrProxNo = novoNo;

};

void removerNoPorValor(No *cabecaLista, int valor){

    if(cabecaLista->ptrProxNo == NULL){
        printf("Lista vazia!\n");
        return;
    }

    No *ptrAtual = cabecaLista->ptrProxNo;
    No *ptrAnterior = cabecaLista;

    while(ptrAtual && ptrAtual->valor != valor){
        ptrAnterior = ptrAtual;
        ptrAtual = ptrAtual->ptrProxNo;
    }

    if(!ptrAtual){
        printf("Valor não encontrado!\n");
        return;
    }

    ptrAnterior->ptrProxNo = ptrAtual->ptrProxNo;
    free(ptrAtual);
}

No* buscarNo(No *cabecaLista, int valor){

    if(cabecaLista->ptrProxNo == NULL){
        printf("Lista vazia!\n");
        return NULL;
    }

    No *ptrAtual = cabecaLista->ptrProxNo;

    while(ptrAtual != NULL && ptrAtual->valor != valor){
        ptrAtual = ptrAtual->ptrProxNo;
    }

    if(ptrAtual == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    }

    return ptrAtual;
}

void imprime(No *cabeca){
    
    No *ptrAux = cabeca ->ptrProxNo;
    
    while(ptrAux != NULL){
        printf("%d\n", ptrAux -> valor);
        ptrAux = ptrAux -> ptrProxNo;
    }
};

int main()
{
    No *cabeca = (No*) malloc(sizeof(No));
    cabeca -> ptrProxNo = NULL;
    
    inserirInicio(cabeca, 5);
    inserirInicio(cabeca, 6);
    inserirInicio(cabeca, 7);
    imprime(cabeca);
    
    inserirFim(cabeca, 9);
    imprime(cabeca);
    
    inserirMeio(cabeca, 1, 2);
    imprime(cabeca);
    
    removerNoPorValor(cabeca, 1);
    imprime(cabeca);

    return 0;
}