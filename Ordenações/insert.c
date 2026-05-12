#include <stdio.h>

int main()
{

	int vetor[] = {5,6,2,12,1};
	int length = sizeof(vetor) / sizeof(vetor[0]);
	int indexMenorValor;
	
	for(int x = 1; x<length; x++){
		if(vetor[x] < vetor[x-1]){
			for()
		}
	}


	for(int y = 0; y < length; y++) {
		printf("%d", vetor[y]);
	}

	return 0;
}