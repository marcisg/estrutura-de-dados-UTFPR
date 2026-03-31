#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct instrumento Instrumento;

struct instrumento {
    char modelo[30];
    char marca[30];
    float preco;
};

int main() {

    setlocale(LC_ALL, "Portuguese");
    int i, n = 2;
    float valorMax;
    Instrumento vetInstrumento[n];


    for(i=0; i<n; i++) {
        printf("Insira o modelo do Instrumento %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetInstrumento[i].modelo);
        printf("Insira a marca do Instrumento %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetInstrumento[i].marca);
        printf("Insira o valor do Instrumento %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%f", &vetInstrumento[i].preco);
    }

    do {

        printf("Insira o valor máximo a pagar por um instrumento: ");
        scanf("%f", &valorMax);

        if(valorMax != 0){
            for(i=0; i<n; i++) {
                if(vetInstrumento[i].preco <= valorMax) {
                    printf("\nInstrumento %d: %s \n", i+1, vetInstrumento[i].modelo);
                    printf("Marca: %s \n", vetInstrumento[i].marca);
                    printf("Valor: %.2f \n", vetInstrumento[i].preco);
                }

            }
        }
    } while(valorMax != 0);

}
