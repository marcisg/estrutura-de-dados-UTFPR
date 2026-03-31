#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct aluno Aluno;

struct aluno{
    int matricula;
    char nome[30];
    float primeiraNota, segundaNota, terceiraNota, mediaFinal;
};

float validaRetornaNota(char prova[30], int i){
    float valorNota = 0;
    do{
        setbuf(stdin, NULL);
        printf("Insira a nota da %s prova do aluno %d: ", prova, i);
        scanf("%f", &valorNota);
    }while(valorNota < 0 || valorNota > 10);

    return valorNota;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    float maiorNotaPrimeira, maiorMediaGeral, menorMediaGeral;
    char vetAlunoMaiorNotaPP[30], vetAlunoMaiorMedia[30], vetAlunoMenorMedia[30];
    int i, n = 3;
    Aluno vetAluno[n];

    for(i=0; i<n ;i++){
        printf("Insira a matrícula do aluno %d: ", i+1);
        scanf("%d", &vetAluno[i].matricula);
        printf("Insira o nome do aluno %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", vetAluno[i].nome);
        vetAluno[i].primeiraNota = validaRetornaNota("primeira", i+1);
        vetAluno[i].segundaNota = validaRetornaNota("segunda", i+1);
        vetAluno[i].terceiraNota = validaRetornaNota("terceira", i+1);
        vetAluno[i].mediaFinal = (vetAluno[i].primeiraNota+vetAluno[i].segundaNota+vetAluno[i].terceiraNota)/3;
    }

    for(i=0; i<n ;i++){
        if(i==0){
            maiorNotaPrimeira = vetAluno[i].primeiraNota;
            strcpy(vetAlunoMaiorNotaPP, vetAluno[i].nome);
        }
        if(maiorNotaPrimeira < vetAluno[i].primeiraNota){
            maiorNotaPrimeira = vetAluno[i].primeiraNota;
            strcpy(vetAlunoMaiorNotaPP, vetAluno[i].nome);
        }
    }
    printf("O(A) aluno(a) %s obteve a maior nota da primeira prova com: %.1f\n", vetAlunoMaiorNotaPP, maiorNotaPrimeira);

    for(i=0; i<n ;i++){
        if(i==0){
            maiorMediaGeral = vetAluno[i].mediaFinal;
            strcpy(vetAlunoMaiorMedia, vetAluno[i].nome);
            menorMediaGeral = vetAluno[i].mediaFinal;
            strcpy(vetAlunoMenorMedia, vetAluno[i].nome);
        }
        if(maiorMediaGeral < vetAluno[i].mediaFinal){
            maiorMediaGeral = vetAluno[i].mediaFinal;
            strcpy(vetAlunoMaiorMedia, vetAluno[i].nome);
        } if(menorMediaGeral > vetAluno[i].mediaFinal){
            menorMediaGeral = vetAluno[i].mediaFinal;
            strcpy(vetAlunoMenorMedia, vetAluno[i].nome);
        }
    }

    printf("O(A) aluno(a) %s obteve a maior média geral com: %.1f\n", vetAlunoMaiorMedia, maiorMediaGeral);
    printf("O(A) aluno(a) %s obteve a menor média geral com: %.1f\n", vetAlunoMenorMedia, menorMediaGeral);

    for(i=0; i<n ;i++){
        if(vetAluno[i].mediaFinal >= 6 && vetAluno[i].mediaFinal <= 10){
            printf("O(A) aluno(a) %s foi aprovado e ficou com média: %.1f\n", vetAluno[i].nome, vetAluno[i].mediaFinal);
        }  else{
            printf("O(A) aluno(a) %s foi reprovado e ficou com média: %.1f\n", vetAluno[i].nome, vetAluno[i].mediaFinal);
        }
    }


}
