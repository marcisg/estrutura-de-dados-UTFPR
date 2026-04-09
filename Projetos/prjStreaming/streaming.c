#include <stdio.h>
#include <stdlib.h>
#include "streaming.h"

struct data{
    int dia;
    int mes;
    int ano;
};

struct streaming{
    char servico[30];
    double valor;
    int recorrencia;
};

struct cliente{
    char nome[30];
    Data *dataNascimento;
    Streaming *contratados;
    int numServ;
};

Cliente *alocaCliente(){
    Cliente *c = (Cliente *) malloc(sizeof(Cliente));
    return c;
}

Cliente *realocaCliente(Cliente *clientes, int numClientes){
    numClientes++;
    clientes = (Cliente *) realloc(clientes, numClientes * sizeof(Cliente));
    return clientes;
}

void cadastraCliente(Cliente *cliente, int numClientes){
    printf("Informe o nome do contratante: ");
    scanf(" %[^\n]", cliente[numClientes].nome);
    cliente[numClientes].dataNascimento = malloc(sizeof(Data));
    do{
        printf("Data de nascimento\nDia: ");
        scanf("%d", &cliente[numClientes].dataNascimento->dia);
        if(cliente[numClientes].dataNascimento->dia <= 0 || cliente[numClientes].dataNascimento->dia > 31){
            printf("\nDia inválido, insira novamente um valor entre 1 e 31.");
        }
    }while(cliente[numClientes].dataNascimento->dia <= 0 || cliente[numClientes].dataNascimento->dia > 31);

    do{
        printf("Mês: ");
        scanf("%d", &cliente[numClientes].dataNascimento->mes);
        if(cliente[numClientes].dataNascimento->mes <= 0 || cliente[numClientes].dataNascimento->mes > 12){
            printf("\nMês inválido, insira novamente um valor entre 1 e 12 equivalente ao número do mês.\n");
        }
    }while(cliente[numClientes].dataNascimento->mes <= 0 || cliente[numClientes].dataNascimento->mes > 12);

    do{
        printf("Ano: ");
        scanf("%d", &cliente[numClientes].dataNascimento->ano);
        if(cliente[numClientes].dataNascimento->ano < 1000 || cliente[numClientes].dataNascimento->ano > 9999){
            printf("\Ano inválido, insira novamente um valor de 4 dígitos para o ano.\n");
        }
    }while(cliente[numClientes].dataNascimento->ano <= 0 || cliente[numClientes].dataNascimento->ano > 9999);

}

Streaming *alocaStreaming(){
    Streaming *s = (Streaming *) malloc(sizeof(Streaming));
    return s;
}

Streaming *realocaStreaming(Streaming *contratados, int numServ){
    numServ++;
    contratados = (Streaming *) realloc(contratados, numServ * sizeof(Streaming));
    return contratados;
}

void adicionaStreaming(Cliente *clientes, int numClientes, int numServ){
    if(numServ == 0){
        clientes[numClientes].contratados = alocaStreaming();
    } else {
        clientes[numClientes].contratados  = realocaStreaming(clientes[numClientes].contratados, numServ);
    }
}

void cadastraStreaming(Cliente *cliente, int numClientes, int numServ){
    printf("Informe o nome do Serviço contratado: ");
    scanf(" %[^\n]", cliente[numClientes].contratados[numServ].servico);
    printf("Informe o valor do Serviço: ");
    scanf("%lf", &cliente[numClientes].contratados[numServ].valor);
    printf("Qual a recorrência do contrato em meses: ");
    scanf("%d", &cliente[numClientes].contratados[numServ].recorrencia);
}

void defineQtd(Cliente *clientes, int numClientes, int numServ){
    clientes[numClientes].numServ = numServ;
}

void imprimeStreaming(Streaming *contratados, int numServ){
    for(int i = 0;i <= numServ;i++){
        printf(". %s ", contratados[i].servico);
        printf("- Valor: %.2lf ", contratados[i].valor);
        printf("- Recorrência: %d meses\n", contratados[i].recorrencia);
    }
}

void imprimeCliente(Cliente *clientes, int numClientes){
    for(int i = 0;i <= numClientes;i++){
        printf("\nNome: %s\n", clientes[i].nome);
        printf("Data de nascimento: %02d/%02d/%d\n\n", clientes[i].dataNascimento->dia, clientes[i].dataNascimento->mes, clientes[i].dataNascimento->ano);
        printf("Serviços contratados: \n");
        imprimeStreaming(clientes[i].contratados, clientes[i].numServ);
        printf("\n");
    }
}

void liberaStructs(Cliente *clientes, int numClientes){
    for(int i = 0; i <= numClientes;i++){
        free(clientes[i].contratados);
        free(clientes[i].dataNascimento);
    }
    free(clientes);
}


void cabecalho(){
    printf("\n#########################################################################\n");
}
