#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct atleta Atleta;
typedef struct dataDeNascimento Data;

struct dataDeNascimento{
    int dia;
    int mes;
    int ano;
};

struct atleta{
    char nome[30];
    char cpf[30];
    Data dataNascimento;
    char modalidade[30];
    float salario;
};

int main(){

    setlocale(LC_ALL, "Portuguese");
    Data nascimeto;
    Atleta atleta01;

    printf("Insira o nome do atleta: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", atleta01.nome);
    printf("CPF: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", atleta01.cpf);
    printf("Data de nascimento dia: ");
    scanf("%d", &atleta01.dataNascimento.dia);
    printf("Data de nascimento mês: ");
    scanf("%d", &atleta01.dataNascimento.mes);
    printf("Data de nascimento ano: ");
    scanf("%d", &atleta01.dataNascimento.ano);
    printf("Modalidade: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", atleta01.modalidade);
    setbuf(stdin, NULL);
    printf("Salário: ");
    scanf("%f", &atleta01.salario);

    printf("Nome: %s\n", atleta01.nome);
    printf("CPF: %s\n", atleta01.cpf);
    printf("Data de nascimento: %d/%d/%d\n", atleta01.dataNascimento.dia, atleta01.dataNascimento.mes, atleta01.dataNascimento.ano);
    printf("Modalidade: %s\n", atleta01.modalidade);
    printf("Salário: %.2f\n", atleta01.salario);
}
