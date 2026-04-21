#include <stdio.h>

int main()
{

    int vetor[] = {5, 8, 9, 0, 3, 4, 6};
    int valorMaior, indexMenor;

    for(int x = 0; x <= 5; x++){
        indexMenor = x;
        for(int y = x+1; y <= 6; y++){
            if(vetor[y] < vetor[indexMenor]){
                indexMenor = y;
            }
        };
        valorMaior = vetor[x];
        vetor[x] = vetor[indexMenor];
        vetor[indexMenor] = valorMaior;
    };

    for(int z = 0; z <= 6; z++){
        printf("%d ", vetor[z]);
    }

    return 0;
}