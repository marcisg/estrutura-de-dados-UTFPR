#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *intervaloLimites(int limiteInf, int limiteSup){
    int intervalo;
    intervalo = limiteSup - limiteInf;
    int *vet = (int *)malloc ((intervalo - 1) * sizeof(int));
    for(int i = 0; i < intervalo - 1; i++){
        vet[i] = limiteInf + 1 + i;
    }
    return vet;
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int limiteSup, limiteInf, i, intervalo;
    int *vet;

    printf("Insira o limite inferior: ");
    scanf("%d", &limiteInf);
    printf("Insira o limite superior: ");
    scanf("%d", &limiteSup);
    intervalo = limiteSup - limiteInf;
    vet = intervaloLimites(limiteInf, limiteSup);
    for(i = 0; i < intervalo - 1; i++){
        printf("%d\t", vet[i]);
    }
    if(intervalo <= 1){
        printf("Nao há números entre os limites.\n");
    }
    free(vet);
}
