#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int contaString(char *str){
    int count = 0;
    while(*str){
        count++;
        *str++;
    }
    return count;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    char minhaString[] = "Curso de Análise e Desenvolvimento de Sistemas";
    int tamString;
    tamString = contaString(minhaString);

    printf("O tamanho da String '%s' é: %d", minhaString, tamString);
}
