#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Alocação de memória em string

char *inverteString(char s[]){
    int i, j, tamanho;
    tamanho = strlen(s);
    // char sInvertida[tamanho]; não é possível usar endereço de memória de variável local como retorno de função;
    char *sInvertida = malloc (tamanho * sizeof(char));

    j = 0;
    for(i = tamanho-1; i >= 0; i--){
        sInvertida[j] = s[i];
        j++;
    }
    sInvertida[j] = '\0';
    return sInvertida;
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    char *s = "ponteiros";
    char *i = inverteString(s);
    printf("%s", i);

    free(i);
    //libera o end de mem que foi alocado dinamicamente dentro da função inverte string
    return 0;
}
