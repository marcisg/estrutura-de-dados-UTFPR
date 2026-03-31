#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void imprimeString(char *str, int tamanhoString){
    for(int i = 0; i < tamanhoString; i++){
        printf("%c", *str);
        str++;
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    char minhaString[] = "Belo dia";

    imprimeString(minhaString, strlen(minhaString));
}
