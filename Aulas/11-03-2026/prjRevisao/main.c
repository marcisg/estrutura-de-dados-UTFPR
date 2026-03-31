#include <stdio.h>
#include <stdlib.h>

//Escopo global
int varGlobal;

//Funçao
//função sem retorno e um parâmetro de entrada
void imprimeRelatorio(char resumido);

//função com retorno e sem parâmetros
int turmaCompleta();

//função com retorno e com parâametros
char* buscaCPF(char nome[], int n); //ou char *nome

int main()
{
    int varInt;
    float varFloat;
    char varUmCaractere;
    char vetorChar[30];
    //indice inicial 0
    //indice final 29

    //Matriz
    int matint[2][3];
    //indices 0..1 linhas
    //indices 0..2 colunas
    double varDouble;

    for(int i; i < 10; i++)
    {
        //variável i de escopo local, só existe dentro do for
    }


    //Manipulação de String no C, demanda o uso de funções da biblioteca string.h
    //#include <string.h>

    //atribuição de strings
    strcpy(varStr, "texto a ser atribuído para varStr");
    //comparação de strings
    if(strcmp(varStr1, varStr2) == 0);
        //strings são iguais

    printf("Hello world!\n");
    return 0;
}
