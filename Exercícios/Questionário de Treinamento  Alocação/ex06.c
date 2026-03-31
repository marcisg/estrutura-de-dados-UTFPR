#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int **alocaMatriz(int linhas, int colunas){
    int **matriz, l;
    matriz = (int **) malloc(linhas * sizeof(int *));

    for(l=0;l < linhas;l++){
        matriz[l] = (int *) malloc(colunas * sizeof(int));
    }
    return matriz;
}

int **preencheMatriz(int **matriz, int linha, int coluna){
    int l, c;
    for(l = 0; l <linha; l++){
        for(c= 0; c < coluna; c++){
            matriz[l][c] = rand() % 100 + 1;
        }
    }
    return matriz;
}

void imprimeMatriz(int **matriz, int linha, int coluna){
    int l, c;
    for(l=0; l<linha;l++){
        for(c=0;c<coluna;c++){
            printf("%d\t", matriz[l][c]);
        }
        printf("\n");
    }
}

void liberaMatriz(int **matriz, int linha){
    for(int l = 0; l < linha;l++){
        free(matriz[l]);
    }
    free(matriz);
}

int **somaDeMatrizes(int **matriz1, int **matriz2, int linha, int coluna){
    int **somaDasMatrizes, l, c;
    somaDasMatrizes = alocaMatriz(linha, coluna);
    for(l = 0; l < linha; l++){
        for(c = 0; c < coluna; c++){
            somaDasMatrizes[l][c] = matriz1[l][c] + matriz2[l][c];
        }
    }
    return somaDasMatrizes;
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int **primeiraMatriz, **segundaMatriz, **somaDasMatrizes, linhas, colunas;
    srand(time(NULL));

    printf("Quantas linhas: ");
    scanf("%d", &linhas);
    printf("Quantas colunas: ");
    scanf("%d", &colunas);

    primeiraMatriz = alocaMatriz(linhas, colunas);
    segundaMatriz = alocaMatriz(linhas, colunas);
    somaDasMatrizes = alocaMatriz(linhas, colunas);
    primeiraMatriz = preencheMatriz(primeiraMatriz, linhas, colunas);
    segundaMatriz = preencheMatriz(segundaMatriz, linhas, colunas);
    printf("\nPrimeira Matriz\n");
    imprimeMatriz(primeiraMatriz, linhas, colunas);
    printf("\nSegunda Matriz\n");
    imprimeMatriz(segundaMatriz, linhas, colunas);
    somaDasMatrizes = somaDeMatrizes(primeiraMatriz, segundaMatriz, linhas, colunas);
    printf("\nSoma das Matrizes 1 e 2\n");
    imprimeMatriz(somaDasMatrizes, linhas, colunas);
    liberaMatriz(primeiraMatriz, linhas);
    liberaMatriz(segundaMatriz, linhas);
    liberaMatriz(somaDasMatrizes, linhas);
}
