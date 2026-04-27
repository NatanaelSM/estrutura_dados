#include <stdio.h>

int main()
{

	int vetor[] = {5,3,1,4,0};
	int length = sizeof(vetor) / sizeof(vetor[0]);
	int indexMenorValor, valorAntigo;

	for(int i = 0; i < length; i++) {
		indexMenorValor = i;
		for(int j = i + 1; j < length; j++) {
			if(vetor[j] < vetor[indexMenorValor]) {
				indexMenorValor = j;
			}
		}
		valorAntigo = vetor[i];
		vetor[i] = vetor[indexMenorValor];
		vetor[indexMenorValor] = valorAntigo;
	}

	for(int y = 0; y < length; y++) {
		printf("%d", vetor[y]);
	}

	return 0;
}