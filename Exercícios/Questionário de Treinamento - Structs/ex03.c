#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct dosesVacina DosesVacina;

struct dosesVacina{
    char nome[30];
    char cidade[30];
    int idade;
};

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i, n = 5;
    DosesVacina vetPaciente[n];

    for(i=0; i<n;i++){
        setbuf(stdin, NULL);
        printf("Insira o nome do paciente %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetPaciente[i].nome);
        printf("Insira a cidade do paciente %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetPaciente[i].cidade);
        printf("Insira a idade do paciente %d: ", i+1);
        scanf("%d", &vetPaciente[i].idade);
    }

    for(i=0; i<n;i++){
        printf("\nPaciente %d: %s \n", i+1, vetPaciente[i].nome);
        printf("Cidade: %s \n", vetPaciente[i].cidade);
        printf("Idade: %d \n", vetPaciente[i].idade);
    }
}
