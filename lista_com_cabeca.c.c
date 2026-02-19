#include <stdio.h>
#include <stdlib.h>

struct Elemento{
    int valor;
    struct Elemento *ptrProximo;
};

typedef struct Elemento ItemLista;

void inserirLista(ItemLista *cabeca, int valor){
    
    ItemLista *ptrAtual = cabeca;
    ItemLista *novoItemLista = (ItemLista*) malloc(sizeof(ItemLista));
    
    novoItemLista -> ptrProximo = NULL;
    novoItemLista -> valor = valor;
    
    while(ptrAtual -> ptrProximo != NULL){
        ptrAtual = ptrAtual -> ptrProximo;
        
    }
    
    ptrAtual -> ptrProximo = novoItemLista;

}

int main()
{
    
    ItemLista cabeca;
    cabeca.ptrProximo = NULL;
    cabeca.valor = 5;
    ItemLista *ptrAtual = &cabeca;
    
    inserirLista(&cabeca, 6);
    inserirLista(&cabeca, 7);
    inserirLista(&cabeca, 8);
    inserirLista(&cabeca, 9);
    
    while(ptrAtual -> ptrProximo != NULL){
      printf("%d \n", ptrAtual-> valor);
      ptrAtual = ptrAtual -> ptrProximo;
    };
    
    printf("%d \n", ptrAtual-> valor);
    return 0;
}