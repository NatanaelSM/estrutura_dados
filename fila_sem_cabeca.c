#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoLigacao {
    int tempoLigacao;
    struct NoLigacao *ptrProxNoLigacao;
    char numeroCelular[12];
    char operadora[25];
} NoLigacao;


NoLigacao* addLigacao(NoLigacao **fimFila, NoLigacao **comecoFila, char numeroCelular[], char operadora[], int tempoLigacao){
    
    NoLigacao *novoNoLigacao = malloc(sizeof(NoLigacao));

    if(!novoNoLigacao){
        printf("Erro ao alocar memória!\n");
        return NULL;
    };
    
    strcpy(novoNoLigacao -> numeroCelular, numeroCelular);
    strcpy(novoNoLigacao -> operadora, operadora);
    novoNoLigacao -> tempoLigacao = tempoLigacao;
    novoNoLigacao -> ptrProxNoLigacao = NULL;

    if(!*fimFila){
        *fimFila = novoNoLigacao;
        *comecoFila = novoNoLigacao;
        return *fimFila;
    }else{
        (*fimFila) -> ptrProxNoLigacao = novoNoLigacao;
        *fimFila = novoNoLigacao;
        return *fimFila;
    }

};

void imprimirLigacoes(NoLigacao **comecoFila){

    NoLigacao *aux = *comecoFila;
    int indexFila = 1;
    
    if(!comecoFila){
        printf("Fila vazia!\n");
        return;
    }

    while(aux){
        printf("--------------------------------\n%d° da fila\nNúmero de origem: %s\nOperadora do número de origem: %s\nTempo da ligação: %d\n",
        indexFila, aux -> numeroCelular, aux -> operadora, aux -> tempoLigacao);
        aux = aux -> ptrProxNoLigacao;
        indexFila++;
    }

    printf("--------------------------------\n")
};

void escolher_acao(NoLigacao **comecoFila, NoLigacao **fimFila){
    int numAcao = -1;

    while(numAcao != 0){

        printf("Digite um dos valores a seguir para realizar uma ação:\n1 - Adicionar ligação a fila de espera\n2 - Atender ligação\n3 - Imprimir ligações\n0 - Sair\n");
        scanf("%d", &numAcao);

        switch(numAcao){
            case 1:
                char numeroCelular[12];
                char operadora[25];
                int tempoLigacao;
                NoLigacao *ligacao;

                printf("Digite o número de origem com DDD:\n");
                scanf("%s", numeroCelular);

                printf("Digite a operadora do número de origem:\n");
                scanf("%s", operadora);

                printf("Digite o tempo de ligação em minutos:\n");
                scanf("%d", &tempoLigacao);

                ligacao = addLigacao(fimFila, comecoFila, numeroCelular, operadora, tempoLigacao);

                if(!ligacao){
                    break;
                };

                printf("O número %s da operadora %s realizou uma ligação de %d minutos!\n", ligacao -> numeroCelular, ligacao -> operadora, ligacao -> tempoLigacao);
                break;

            case 2:
                //atenderLigacao(&fila);
                break;

            case 3:
                imprimirLigacoes(comecoFila);
                break;

            case 0:
                printf("Programa finalizado!\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;

        };
    };
};


int main()
{
    NoLigacao *comecoFila = NULL;
    NoLigacao *fimFila = NULL;

    escolher_acao(&comecoFila, &fimFila);

    return 0;
}