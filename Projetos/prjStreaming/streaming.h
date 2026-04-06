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

Cliente *alocaCliente();
Cliente *realocaCliente(Cliente *clientes, int numClientes);
void cadastraCliente(Cliente *cliente, int numClientes);
Streaming *alocaStreaming();
Streaming *realocaStreaming(Streaming *contratados, int numServ);
void cadastraStreaming(Cliente *cliente, int numClientes, int numServ);
void imprimeStreaming(Streaming *contratados, int numServ);
void imprimeCliente(Cliente *clientes, int numClientes);
void liberaStructs(Cliente *clientes, int numClientes);
void cabecalho();
