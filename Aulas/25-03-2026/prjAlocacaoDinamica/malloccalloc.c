#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exemplo de uso de alocação dinâmica de memória
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *vet;
    int num;
    printf("Informe o número de elementos que pretende armazenar: ");
    scanf("%d", &num);
    //aloca memória necessária para armazenar a quantidade informada pelo usuário sem verificar se há lixo
    vet = (int *) malloc(num * sizeof(int)); //(int *) força o retorno a ser um inteiro de ponteiro
    //aloca memória necessária para armazenar a quantidade informada pelo usuário verificando se há lixo
    //vet = (int *) calloc(num, sizeof(int));
    if(vet == NULL){
        printf("\nErro: não foi possível alocar memória.\n");
        system("pause"); //pausa para dar tempo de ler a msg
        exit(1); //sai do programa e indica saída anormal
    }
    int i;
    for(i = 0; i < num; i++){
        printf("\nDigite o valor da posição %d: ", i);
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < num; i++){
        printf("Posição %d: %d\n", i, vet[i]);
    }
    //libera da memória o vetor alocado dinamicamente
    free(vet);
    return 0;
}
