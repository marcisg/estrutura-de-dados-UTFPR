#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct livro Livro;

struct livro {
    char titulo[30];
    char autor[30];
    int ano;
};

void imprimeLivro(Livro book){
    printf("Título: %s\n", book.titulo);
    printf("Autor: %s\n", book.autor);
    printf("Ano: %d\n", book.ano);
    printf("\n");
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int i = 0, j, n = 5;
    int busca, buscaAno, totLivros;
    Livro livros[n];
    char continuar, buscaTitulo[30];

    do {
        printf("----- CADASTRO DE LIVRO -----\n");
        printf("TÍTULO: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", livros[i].titulo);
        printf("AUTOR: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", livros[i].autor);
        printf("ANO: ");
        scanf("%d", &livros[i].ano);
        if(i<n-1) {
            printf("\nDeseja cadastrar mais um livro? ");
            setbuf(stdin, NULL);
            scanf("%c", &continuar);
            printf("\n");
        }

        i++;
    } while((continuar == 'S' || continuar == 's') && i < n);

    totLivros = i;

    do {
        printf("\n1 - TÍTULO\n2 - ANO\nFazer a busca por: ");
        scanf("%d", &busca);

        switch(busca) {
        case 1:
            printf("Digite o título: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", buscaTitulo);
            printf("\nRESULTADO DA BUSCA: \n\n");
            j = 0;
            for(i = 0; i < totLivros; i++) {
                if(strcmp(buscaTitulo, livros[i].titulo) == 0) {
                    imprimeLivro(livros[i]);
                    j++;
                }
            }
            if(j == 0) {
                printf("Nenhum livro encontrado.\n");
            }
            break;
        case 2:
            printf("Digite o ano: ");
            scanf("%d", &buscaAno);
            printf("\nRESULTADO DA BUSCA: \n\n");
            j = 0;
            for(i = 0; i < totLivros; i++) {
                if(buscaAno == livros[i].ano) {
                    imprimeLivro(livros[i]);
                    j++;
                }
            }
            if(j == 0) {
                printf("Nenhum livro encontrado.\n");
            }
            break;
        default:
            printf("\nOpção inválida.\n");
        }
        printf("\nDeseja fazer outra busca? ");
        setbuf(stdin, NULL);
        scanf("%c", &continuar);
        printf("\n");
    } while(continuar == 'S' || continuar == 's');
}
