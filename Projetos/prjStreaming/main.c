#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//precisa das validações de entradas e arrumar no padrão TAD

typedef struct data Data;
typedef struct streaming Streaming;
typedef struct cliente Cliente;

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
    printf("Data de nascimento\nDia: ");
    scanf("%d", &cliente[numClientes].dataNascimento->dia);
    printf("\nMês: ");
    scanf("%d", &cliente[numClientes].dataNascimento->mes);
    printf("\nAno: ");
    scanf("%d", &cliente[numClientes].dataNascimento->ano);
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

void cadastraStreaming(Cliente *cliente, int numClientes, int numServ){
    printf("Informe o nome do Serviço contratado: ");
    scanf(" %[^\n]", cliente[numClientes].contratados[numServ].servico);
    printf("Informe o valor do Serviço: ");
    scanf("%lf", &cliente[numClientes].contratados[numServ].valor);
    printf("Qual a recorrência do contrato em meses: ");
    scanf("%d", &cliente[numClientes].contratados[numServ].recorrencia);
}

void imprimeStreaming(Streaming *contratados, int numServ){
    for(int i = 0;i <= numServ;i++){
        printf(". %s ", contratados[i].servico);
        printf("- Valor: %.2lf ", contratados[i].valor);
        printf("- Recorrência: %d\n", contratados[i].recorrencia);
    }
}

void imprimeCliente(Cliente *clientes, int numClientes){
    for(int i = 0;i <= numClientes;i++){
        printf("\nNome: %s\n", clientes[i].nome);
        printf("Data de nascimento: %d/%d/%d\n\n", clientes[i].dataNascimento->dia, clientes[i].dataNascimento->mes, clientes[i].dataNascimento->ano);
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
            printf("Informar outro Serviço?");
            scanf(" %c", &alocarStreaming);
            if(alocarStreaming == 's' || alocarStreaming == 'S'){
               numServ++;
            }
        }while(alocarStreaming == 's' || alocarStreaming == 'S');

        //guardando a quantidade de serviços de cada cliente em uma variável dentro da sua struct
        clientes[numClientes].numServ = numServ;

        //continuar o loop de cadastrar usuários
        printf("Deseja cadastrar outro contratante? (S/N)");
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
