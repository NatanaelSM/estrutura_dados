#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *ptrProxNo;
};

typedef struct No No;

void inserirLista(No *cabecaLista, int valorNovoNo){

    No *ptrAtual = cabecaLista;
    No *novoNo = malloc(sizeof(No));

    if (novoNo == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novoNo->valor = valorNovoNo;
    novoNo->ptrProxNo = NULL;

    while (ptrAtual->ptrProxNo != NULL){
        ptrAtual = ptrAtual->ptrProxNo;
    }

    ptrAtual->ptrProxNo = novoNo;
}

void imprime(){};

int main()
{   
    No *cabeca;
    cabeca -> ptrProxNo = NULL;

    inserirLista(cabeca, 5);
    inserirLista(cabeca, 6);
    inserirLista(cabeca, 7);
    inserirLista(cabeca, 8);
    inserirLista(cabeca, 9);
    
    return 0;
}