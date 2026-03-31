#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct filme Filme;

struct filme{
    char titulo[30];
    char diretor[30];
    char genero[30];
    int duracao;
    int nota;
};

void imprimeFilme(Filme filme){
    printf("Título: %s\n", filme.titulo);
    printf("Diretor: %s\n", filme.diretor);
    printf("Gênero: %s\n", filme.genero);
    printf("Duração: %d\n", filme.duracao);
    printf("Nota: %d\n", filme.nota);
}

int buscaPorGenero(char genero[], char comp[]){
    return strcmp(genero, comp) == 0;
}

int buscaPorDiretor (char diretor[], char comp[]){
    return strcmp(diretor, comp) == 0;
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int i = 0, n = 10, j;
    int totFilmes;
    char continuar, buscaGenero[30], buscaDiretor[30];
    Filme filme[n], maiorFilme;

    do{
        printf("Título: ");
        scanf(" %[^\n]", &filme[i].titulo);
        printf("Diretor: ");
        scanf(" %[^\n]", &filme[i].diretor);
        printf("\n------GÊNEROS------\n\n1 - Ação\n2 - Animação\n3 - Aventura\n4 - Comédia\n5 - Drama\n6 - Ficção Científica\n7 - Fantasia\n8 - Guerra\n");
        printf("9 - Musical\n10 - Policial/Crime\n11 - Romance\n12 - Suspense\n13 - Terror/Horror\n14 - Faroeste\n\nEscreva o gênero: ");
        scanf(" %[^\n]", &filme[i].genero);
        printf("Duração (em minutos): ");
        scanf(" %d", &filme[i].duracao);
        printf("Estrelas (de 1 a 5): ");
        scanf("%d", &filme[i].nota);
        printf("Deseja cadastrar mais um filme?\n");
        scanf(" %c", &continuar);
        i++;
    }while(continuar == 'S' || continuar == 's');

    totFilmes = i;

    maiorFilme = filme[0];

    for(i = 1; i < totFilmes; i++){
        if(maiorFilme.duracao < filme[i].duracao){
            maiorFilme = filme[i];
        }
    }

    printf("\nO filme com maior duração é: \n");
    imprimeFilme(maiorFilme);
    printf("\n");

    printf("Os filmes com 5 estrelas são: \n");
    for(i = 0; i < totFilmes; i++){
        if(filme[i].nota == 5 ){
            imprimeFilme(filme[i]);
            printf("\n");
        }
    }
    printf("Os filmes com 1 estrela são: \n");
    for(i = 0; i < totFilmes; i++){
        if(filme[i].nota == 1 ){
            imprimeFilme(filme[i]);
            printf("\n");
        }
    }

    do{
        printf("Insira um Gênero para busca: ");
        scanf(" %[^\n]", buscaGenero);
        j = 0;
        for(i=0;i<totFilmes;i++){
            if(buscaPorGenero(buscaGenero, filme[i].genero) == 1){
                imprimeFilme(filme[i]);
                j++;
            }
        }
        if(j == 0){
            printf("Não existem filmes desse Gênero na lista!\n");
        }
        printf("Deseja pesquisar por outro Gênero?\n");
        scanf(" %c", &continuar);
    }while(continuar == 'S' || continuar == 's');

    do{
        printf("Insira um Diretor para busca: ");
        scanf(" %[^\n]", buscaDiretor);
        j = 0;
        for(i=0;i<totFilmes;i++){
            if(buscaPorDiretor(buscaDiretor, filme[i].diretor) == 1){
                imprimeFilme(filme[i]);
                j++;
            }
        }
        if(j == 0){
            printf("Não existem filmes com esse Diretor na lista!\n");
        }
        printf("Deseja pesquisar por outro Diretor?\n");
        scanf(" %c", &continuar);
    }while(continuar == 'S' || continuar == 's');

}
