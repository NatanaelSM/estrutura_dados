#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *left_no;
	struct No *right_no;
} No;

No* comparar(No *noComparacao, int valorInserir) {
	No *aux = noComparacao;

	if(aux -> valor >= valorInserir) {
		if(aux -> left_no == NULL) {
			return &aux -> left_no;
		}
		aux = aux -> left_no;
		comparar(aux, valorInserir);
	}else{
        if(aux -> right_no == NULL) {
		    return &aux -> right_no;
	    }
        aux = aux -> right_no;
	    comparar(aux,valorInserir);
    }
    
}


void insere(No **raiz, int valorInserir) {

	No *novoNo = malloc(sizeof(No));

	if(!novoNo) {
		printf("Erro ao alocar memória!");
		return;
	}
    
    novoNo -> valor = valorInserir;
	novoNo -> left_no = NULL;
	novoNo -> right_no = NULL;

	if(*raiz == NULL) {
		*raiz = novoNo;
        printf("Raiz adicionada! %d", (*raiz) -> valor);
        return;
	}

    novoNo = comparar(*raiz, valorInserir);
    printf("Valor %d inserido com sucesso!\n", novoNo->valor);
}

int main()
{
	No *raiz = NULL;
	insere(&raiz, 10);
	insere(&raiz, 5);
	insere(&raiz, 7);
	insere(&raiz, 13);
	insere(&raiz, 17);

	return 0;
}