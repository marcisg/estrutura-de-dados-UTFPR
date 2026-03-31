#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exemplo de uso de Ponteiros

int main(){

    setlocale(LC_ALL, "Portuguese");

    int n = 10;
    char c = 'a';
    int *pn = &n; //ponteiro de inteiro que guarda o endereço de n
    char *pc = &c; //ponteiro de char que guarda o endereço de c

    //imprime o conteúdo das variáveis
    printf("O valor da variável n é: %d\n", n);
    printf("O valor da variável c é: %c\n", c);
    //imprime o endereço das variáveis
    printf("O endereço da variável n é: %ld\n", &n);
    printf("O endereço da variável c é: %ld\n", &c);
    //imprime o conteúdo das variáveis do tipo ponteiro
    printf("pn aponta para o endereço de n que é: %ld\n", pn);
    printf("pc aponta para o endereço de c que é: %ld\n", pc);
    //imprime o conteúdo das variáveis apontadas pelo ponteiros
    printf("No endereço apontado por pn está o conteúdo: %d\n", *pn);
    printf("No endereço apontado por pc está o conteúdo: %c\n", *pc);

    *pn = 20;
    printf("Agora no endereço apontado por pn está o conteúdo: %d\n", *pn);
    printf("O valor da variável n é: %d\n", n);

    return 0;
}
