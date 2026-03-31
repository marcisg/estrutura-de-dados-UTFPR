#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void alocarNota(double **notas, int num){
    *notas = (double *) realloc(*notas, num * sizeof(double));
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num = 1;
    double *notas, total = 0, media, maior, menor;
    char repetir;

    notas = (double *) malloc(num * sizeof(double));
    do{
        printf("Insira uma nota: ");
        scanf("%lf", &notas[num - 1]);
        printf("Deseja inserir mais uma nota?(S/N)");
        scanf(" %c", &repetir);
        if(repetir == 's' || repetir == 'S'){
            num++;
            alocarNota(&notas, num);
        }
        }while (repetir == 's' || repetir == 'S');

    maior = notas[0];
    menor = notas[0];

    for(int i = 0;i < num;i++){
        total = total + notas[i];
        if(maior < notas[i]){
            maior = notas[i];
        }
        if(menor > notas[i]){
            menor = notas[i];
        }
    }
    media = total/num;
    printf("Média das notas: %.1lf\n", media);
    printf("A maior nota é: %.1lf\n", maior);
    printf("A menor nota é: %.1lf\n", menor);

    free(notas);
}
