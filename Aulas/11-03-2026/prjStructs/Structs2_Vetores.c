#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno Aluno; //cria-se um apelido para substituir duas palavras

struct aluno {
    char nome[30];
    int RA;
    float coeficiente;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Aluno aluno_1;
    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", aluno_1.nome);
    printf("Informe o RA: ");
    scanf("%d", &aluno_1.RA);
    printf("Informe o coeficiente: ");
    scanf("%f", &aluno_1.coeficiente);

    printf("Nome: %s \n", aluno_1.nome);
    printf("RA: %d \n", aluno_1.RA);
    printf("Coeficiente: %.4f \n", aluno_1.coeficiente);

    Aluno aluno_2 = {"Maria", 45678, 0.925};

    aluno_2 = aluno_1;//Sobrescreve os dados do aluno_2

    printf("Nome aluno 2: %s \n", aluno_2.nome);
    printf("RA: %d \n", aluno_2.RA);
    printf("Coeficiente: %.4f \n", aluno_2.coeficiente);



    return 0;
}
