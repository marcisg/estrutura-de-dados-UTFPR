typedef struct data Data;
typedef struct streaming Streaming;
typedef struct cliente Cliente;

Cliente *alocaCliente();
Cliente *realocaCliente(Cliente *clientes, int numClientes);
void cadastraCliente(Cliente *cliente, int numClientes);
Streaming *alocaStreaming();
Streaming *realocaStreaming(Streaming *contratados, int numServ);
void adicionaStreaming(Cliente *clientes, int numClientes, int numServ);
void cadastraStreaming(Cliente *cliente, int numClientes, int numServ);
void defineQtd(Cliente *clientes, int numClientes, int numServ);
void imprimeStreaming(Streaming *contratados, int numServ);
void imprimeCliente(Cliente *clientes, int numClientes);
void liberaStructs(Cliente *clientes, int numClientes);
void cabecalho();
