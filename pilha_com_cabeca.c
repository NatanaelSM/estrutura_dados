#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int pesoAnilha;
    struct No *ptrProxNo;
} No;

void addPeso(No *cabeca, int valorPesoAnilha){

    No *novoNo = malloc(sizeof(No));

    if(!novoNo){
        printf("Erro ao alocar memória!\n");
        return;
    };

    novoNo -> pesoAnilha = valorPesoAnilha;
    novoNo -> ptrProxNo = cabeca -> ptrProxNo;
    cabeca -> ptrProxNo = novoNo;

    printf("Anilha de %dkg adicionada no topo da pilha!\n", valorPesoAnilha);
}; 

void rmvPeso(No *cabeca){

    if(cabeca -> ptrProxNo == NULL || !cabeca){
        printf("Pilha vazia ou sem pesos adicionados!\n");
        return;
    };

    No *lixo = cabeca -> ptrProxNo;

    cabeca -> ptrProxNo = lixo -> ptrProxNo;
    printf("Anilha de %dkg retirada do topo da pilha!\n", lixo -> pesoAnilha);
    free(lixo);
};

void escolher_acao(No *cabeca){
    int numAcao = -1;

    while(numAcao != 0){

        printf("Digite um dos valores a seguir para realizar uma ação:\n1 - Adicionar 20kg no leg press\n2 - Adicionar 10kg no leg press\n3 - Adicionar 5kg no leg press\n4 - Retirar última anilha\n0 - Sair\n");
        scanf("%d", &numAcao);

        switch(numAcao){
            case 1:
                addPeso(cabeca, 20);
                break;
            case 2:
                addPeso(cabeca, 10);
                break;
            case 3:
                addPeso(cabeca, 5);
                break;
            case 4:
                rmvPeso(cabeca);
                break;
            case 0:
                printf("Programa finalizado!\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
};


int main()
{
    No *cabeca = malloc(sizeof(No));

    if(!cabeca){
        printf("Erro ao alocar memória!\n");
    };
    
    cabeca -> ptrProxNo = NULL;

    escolher_acao(cabeca);

    return 0;
}