#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int tam = 50;
    int *vet, i;

    vet = (int *) malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){
        vet[i] = rand() % 100 + 1;
    }

    for(i = 0; i < tam; i++){
        printf("%d\t", vet[i]);
    }

    free(vet);
    return 0;
}
