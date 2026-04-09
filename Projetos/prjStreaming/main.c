#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "streaming.h"

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
            adicionaStreaming(clientes, numClientes, numServ);
            //cadastrando Streamings
            cadastraStreaming(clientes, numClientes, numServ);

            //continuar o loop de cadastrar serviços
            printf("Informar outro Serviço? (S/N) ");
            scanf(" %c", &alocarStreaming);

            //se o cliente quiser cadastrar mais um streaming a quantidade de serviços aumenta
            if(alocarStreaming == 's' || alocarStreaming == 'S'){
               numServ++;
            }
        }while(alocarStreaming == 's' || alocarStreaming == 'S');

        //guardando a quantidade de serviços de cada cliente em uma variável dentro da sua struct
        defineQtd(clientes, numClientes, numServ);

        //continuar o loop de cadastrar usuários
        printf("Deseja cadastrar outro contratante? (S/N) ");
        scanf(" %c", &alocarCliente);

        //se o cliente quiser cadastrar mais um cliente a quantidade número de clientes aumenta
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
