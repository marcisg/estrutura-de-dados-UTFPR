#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "streaming.h"

//precisa das validações de entradas

int main(){

    setlocale(LC_ALL, "Portuguese");
    cabecalho();
    printf("\n\t\t\tGESTÃO DE STREAMINGS\n");
    cabecalho();
    printf("\n");
    Cliente *clientes;
    char alocarCliente, alocarStreaming;
    int numClientes = 0, numServ;
    do{
        //alocando clientes
        if(numClientes == 0){
            clientes = alocaCliente();
        } else{
            clientes  = realocaCliente(clientes, numClientes);
        }
        //limpando o n de serviços do outro cliente
        numServ = 0;

        //cadastrando nome e data
        cadastraCliente(clientes, numClientes);

        //alocando streamings
        do{
            if(numServ == 0){
                clientes[numClientes].contratados = alocaStreaming();
            } else{
                clientes[numClientes].contratados  = realocaStreaming(clientes[numClientes].contratados, numServ);
            }

            //cadastrando Streamings
            cadastraStreaming(clientes, numClientes, numServ);

            //continuar o loop de cadastrar serviços
            printf("Informar outro Serviço? ");
            scanf(" %c", &alocarStreaming);
            if(alocarStreaming == 's' || alocarStreaming == 'S'){
               numServ++;
            }
        }while(alocarStreaming == 's' || alocarStreaming == 'S');

        //guardando a quantidade de serviços de cada cliente em uma variável dentro da sua struct
        clientes[numClientes].numServ = numServ;

        //continuar o loop de cadastrar usuários
        printf("Deseja cadastrar outro contratante? (S/N) ");
        scanf(" %c", &alocarCliente);
        if(alocarCliente == 's' || alocarCliente == 'S'){
            numClientes++;
        }
    }while(alocarCliente == 's' || alocarCliente == 'S');

    //prints e leberar mallocs utilizados
    cabecalho();
    printf("\n\t\t\tDADOS CADASTRADOS\n");
    cabecalho();
    imprimeCliente(clientes, numClientes);
    liberaStructs(clientes, numClientes);
    return 0;
}
