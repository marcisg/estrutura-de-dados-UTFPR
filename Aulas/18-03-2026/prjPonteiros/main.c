#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Exemplo de uso de ponteiro de struct

typedef struct cliente Cliente;

struct cliente{
    char nome[30];
    char rua[30];
    int numero;
};

void alteraEndereco(Cliente *cli, char rua[], int num){
    strcpy(cli->rua, rua); // cli->rua = rua
    cli->numero = num;
}

void imprimeCliente(Cliente *cli){
    printf("\nNome: %s", cli->nome);
    printf("\nRua: %s", cli->rua);
    printf("\nNúmero: %d", cli->numero);
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    Cliente cl;

    strcpy(cl.nome, "Maria");
    strcpy(cl.rua, "Rua Guarani");
    cl.numero = 10;

    imprimeCliente(&cl);
    alteraEndereco(&cl, "Avenida Tupi", 20);
    imprimeCliente(&cl);


    return 0;
}
