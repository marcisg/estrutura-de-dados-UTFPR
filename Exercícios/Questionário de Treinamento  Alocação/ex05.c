#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno Aluno;

struct aluno{
    char nome[30];
    int ra;
    int telefone[11];
    char email[30];
};

void alocarAluno(Aluno **aluno, int quantidade){

    *aluno = (Aluno *) malloc(quantidade * sizeof(Aluno));//quando fizer malloc, calloc ou realloc em função temos que usar ponteiro de ponteiro
                                                          //para a alteração do endereço da memória não ser apenas em uma cópia de aluno, mas sim no
                                                          //vetor original. Se a mesma operação fosse feita na main, não seria necessário pois a variável
                                                          //estaria em seu escopo original, mudando na main ela já mudaria automaticamente o aluno para
                                                          //outro endereço de memória.
}

void cadastraAluno(Aluno aluno[], int quantidade){
    for(int i = 0;i< quantidade;i++){
        printf("Nome: ");
        scanf(" %[^\n]", aluno[i].nome);
        printf("RA: ");
        scanf("%d", &aluno[i].ra);
        printf("Telefone: ");
        scanf(" %[^\n]", aluno[i].telefone);
        printf("Email: ");
        scanf(" %[^\n]", aluno[i].email);
    }
}

void imprimeAluno(Aluno aluno[], int quantidade){
    for(int i = 0;i< quantidade;i++){
        printf("\nAluno %d\n", i+1);
        printf("Nome: %s\n", aluno[i].nome);
        printf("RA: %d\n", aluno[i].ra);
        printf("Telefone: %s\n", aluno[i].telefone);
        printf("Email: %s\n", aluno[i].email);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int quantidade;
    Aluno *aluno;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);

    alocarAluno(&aluno, quantidade);
//    aluno = (Aluno *) malloc(quantidade * sizeof(Aluno));

    cadastraAluno(aluno, quantidade);

    imprimeAluno(aluno, quantidade);

    free(aluno);
}
