#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int comparaString(char *sa, char *sb){
    int resultado = 0, diff = 0, tam;
    tam = strlen(sa);

    if(strlen(sa) == strlen(sb)){
        for(int i = 0; i < tam;i++){
            if(*sa != *sb){
                diff++;
                break;
            }
            sa++;
            sb++;
        }
        if(diff == 0){
            resultado++;
        }
    }
        return resultado;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    char str1[] = "Bom dia";
    char str2[] = "Bom aid";

    if(comparaString(str1, str2) == 1){
        printf("As strings são iguais.");
    } else{
        printf("As strings não são iguais.");
    }
}
