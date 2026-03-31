#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exemplo de uso de vetor com argumento/parâmetro de função

int alteraVetor(int v[], int n){//pode-se declarar *v porém não da pra saber se é um vetor ou outro Tipo
    v[0] = n;
}

char *copiaParteStr(char c, char *str){
    while(*str && c != *str){//só para se o c for igual ao conteúdo do ponteiro, ou a string acabar
        str = str + 1; // artimética de ponteiros para avançar na string
    }
    return str;//retorna o ponteiro contendo o restante da string
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int n = 5;
    int v[] = {1, 2, 3, 4, 5};
    alteraVetor(v, n);
    for(int i = 0; i < n; i++){
        printf("%d\t", v[i]);
    }
    char s[] = "Boa noite";
    char c = 'a';
    char *pc;
    pc = copiaParteStr(c, s);
    if(*pc){ //se há um valor válido associado ao ponteiro
        printf("\n%s", pc);
    } else{
        printf("\nCacartére não encontrado na string.");
    }


    return 0;
}
