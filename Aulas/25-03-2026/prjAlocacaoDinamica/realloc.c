#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exemplo de uso de alocação dinâmica de memória
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *vet;
    int num = 5;

    vet = (int *) malloc(num * sizeof(int)); //(int *) força o retorno a ser um inteiro de ponteiro
    if(vet){
        int i;
        for(i = 0; i < num; i++){
            vet[i] = i+1;
        }
        for(i = 0; i < num; i++){
            printf("%d\n", vet[i]);
        }
        printf("\n");
        //Diminui o tamanho do array
        num = 3;
        vet = (int *) realloc(vet, num * sizeof(int));
        for(i = 0; i < num; i++){
            printf("%d\n", vet[i]);
        }
        printf("\n");
        //Aumenta o tamanho do array
        num = 10;
        vet = (int *) realloc(vet, num * sizeof(int));
        for(i = 0; i < num; i++){
            printf("%d\n", vet[i]);
        }
    }
//    int i;
//    for(i = 0; i < num; i++){
//        printf("\nDigite o valor da posição %d: ", i);
//        scanf("%d", &vet[i]);
//    }
//    for(i = 0; i < num; i++){
//        printf("Posição %d: %d\n", i, vet[i]);
//    }
    free(vet);
    return 0;
}
