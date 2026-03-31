#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    //int tam = 5;
    int vet[5] = {10, 20, 30, 40, 50};
    printf("Vetor na posição 0: %d\n", *vet);
    printf("Vetor na posição 1: %d\n", *(vet + 1));
    printf("Vetor na posição 2: %d\n", *(vet + 2));
    printf("Vetor na posição 3: %d\n", *(vet + 3));
    printf("Vetor na posição 4: %d\n", *(vet + 4));
}
//também funciona com for
//for(int i = 0 ; i < tam;i++){
//        printf("Vetor na posição %d: %d\n",i , *(vet + i));
//    }
