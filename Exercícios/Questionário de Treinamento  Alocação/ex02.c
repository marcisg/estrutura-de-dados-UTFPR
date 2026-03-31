#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int tam = 50;
    int *vet, i;

    vet = (int *) calloc(tam, sizeof(int));
    for(i = 0; i < tam; i++){
        vet[i] = 1856715;
        printf("%d\t", vet[i]);
    }
}
