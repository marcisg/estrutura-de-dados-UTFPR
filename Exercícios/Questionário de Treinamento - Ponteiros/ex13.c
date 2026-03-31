#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void copiaString(char *destino, char *origem){
    while(*origem){
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    char str[] = "Estrutura de Dados";
    int tam = strlen(str);
    char strCopia[tam];

    copiaString(strCopia, str);
    printf("%s", strCopia);
}
