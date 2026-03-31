#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int *a, int *b){
    return *a + *b;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int num1, num2;

    printf("Insira o primeiro valor: ");
    scanf("%d", &num1);
    printf("Insira o segundo valor: ");
    scanf("%d", &num2);

    printf("A soma de %d + %d é: %d", num1, num2, soma(&num1, &num2));
}
