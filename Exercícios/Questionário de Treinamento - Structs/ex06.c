#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct alunos Alunos;

struct alunos{
    char nome[30];
    char matricula[30];
    float mediaFinal;
};

float validaRetornaNota(int i){
    float valorNota = 0;
    do{
        setbuf(stdin, NULL);
        printf("Insira a média final do aluno %d: ", i+1);
        scanf("%f", &valorNota);
    }while(valorNota < 0 || valorNota > 10);

    return valorNota;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int i, j = 0, k = 0, n = 8;
    Alunos vetAlunos[n], vetAprovados[n], vetReprovados[n];

    for(i=0; i<n;i++){
        printf("Insira o nome do aluno %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetAlunos[i].nome);
        printf("Insira a matrícula do aluno %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetAlunos[i].matricula);
        vetAlunos[i].mediaFinal = validaRetornaNota(i);
    }

    for(i=0; i<n;i++){
        if(vetAlunos[i].mediaFinal >= 5){
            vetAprovados[j] = vetAlunos[i];
            j++;
        } else{
            vetReprovados[k] = vetAlunos[i];
            k++;
        }
    }

    printf("\n------------- APROVADOS -------------\n");
    for(i=0;i<j;i++){
        printf("Nome: %s\n", vetAprovados[i].nome);
        printf("Matrícula: %s\n", vetAprovados[i].matricula);
        printf("Média final: %.1f\n", vetAprovados[i].mediaFinal);
    }

    printf("\n------------- REPROVADOS -------------\n");
    for(i=0;i<k;i++){
        printf("Nome: %s\n", vetReprovados[i].nome);
        printf("Matrícula: %s\n", vetReprovados[i].matricula);
        printf("Média final: %.1f\n", vetReprovados[i].mediaFinal);
    }


}
