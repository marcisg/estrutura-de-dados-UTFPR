#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct pedido Pedido;

struct pedido {
    char cliente[30];
    char itens[100];
    float valorTotal;
};

int main() {

    setlocale(LC_ALL, "Portuguese");
    int i, j =0,;
    char  continuar;
    Pedido vetPedido[1000];

    do {
        for(i=j; i==j; j++) {
            printf("Nome do cliente: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", vetPedido[j].cliente);
            printf("Itens do pedido: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", vetPedido[j].itens);
            printf("Insira o valor total dos produtos: ");
            scanf("%f", &vetPedido[j].valorTotal);
            setbuf(stdin, NULL);

            printf("\n-------------Pedido %d -------------\n", j+1);
            printf("Cliente: %s\n", vetPedido[j].cliente);
            printf("Itens: %s\n", vetPedido[j].itens);
            printf("Valor Total: %.2f\n\n", vetPedido[j].valorTotal);
        }

        printf("Deseja ir para o próximo pedido? (S para sim ou N para não)\n");
        scanf("%c", &continuar);
    } while(continuar == 'S' || continuar == 's');

}
