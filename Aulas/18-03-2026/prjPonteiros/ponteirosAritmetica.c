#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exemplo de artimética de Ponteiros com vetor

int main(){

    setlocale(LC_ALL, "Portuguese");

    short int vet[] = {20, 30, 40, 50, 60}; //short int ocupa 2 bytes
    short int *p = vet; // o nome do vetor da acesso ao primeiro endereço de memória, então não precisa & comercial

    printf("p aponta para o endereço: %ld\n", p);//endereço de vet[0]
    printf("O valor guardado no endereço acima é: %d", *p);//valor em vet[0]

    p = p + 2;//aritmética de ponteiros, avança duas posições

    printf("\np = p + 2\n");
    printf("p aponta para o endereço: %ld\n", p);//endereço de vet[2]
    printf("O valor guardado no endereço acima é: %d", *p);//valor em vet[2]

    p = p - 1;

    printf("\np = p - 1\n");
    printf("p aponta para o endereço: %ld\n", p);//endereço de vet[1]
    printf("O valor guardado no endereço acima é: %d", *p);//valor em vet[1]



    return 0;
}
