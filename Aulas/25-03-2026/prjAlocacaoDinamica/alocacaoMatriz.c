#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Exemplo de uso de alocação dinânmica de memória em matrizes dinânmicas

int **alocaMatriz(int nLinhas, int nColunas){
    int **m, l, c;
    //alocamos um vetor com um ponteiro para cada inha
    m = (int **) malloc(nLinhas * sizeof(int));
    //fazemos cada ponteiro apontar para uma linha
    for(l = 0; l < nLinhas; l++){
        m[l] = (int *) calloc(nColunas, sizeof(int *));
    }
    return m;
}
void imprimeMatriz(int **m, int nLinhas, int nColunas){
    for(int l = 0; l < nLinhas; l++){
        for(int c = 0; c < nColunas; c++){
            printf("%d\t", m[l][c]);
            //poderia ser usado *(*(m+1)+c)
        }
        printf("\n");
    }
}
void liberaMatriz(int **m, int nLinhas){
    for(int l = 0; l <nLinhas; l++){
        free(m[l]); //libera os vetores apontados por cada linha
    }
    free(m); //libera a matriz como um todo
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int nLinhas = 4, nColunas = 5;
    int **m = alocaMatriz(nLinhas, nColunas);
    imprimeMatriz(m, nLinhas, nColunas);
    liberaMatriz(m, nLinhas);

    return 0;
}
