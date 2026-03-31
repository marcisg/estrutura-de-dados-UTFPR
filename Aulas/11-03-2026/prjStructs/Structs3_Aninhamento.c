#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//cria-se um apelido para substituir as duas palvras struct ponto por apenas Ponto e struct triangulo por Triangulo

typedef struct ponto Ponto;
typedef struct triangulo Triangulo;

struct ponto {
    int x;
    int y;
};

struct triangulo {
    Ponto vetPontos[3];
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Triangulo t;
    t.vetPontos[0].x = 0;
    t.vetPontos[0].y = 0;
    t.vetPontos[1].x = 5;
    t.vetPontos[1].y = 0;
    t.vetPontos[2].x = 1;
    t.vetPontos[2].y = 5;
    for(int i = 0; i <3; i++){
        printf("x: %d, y: %d\n", t.vetPontos[i].x, t.vetPontos[i].y);
    }

    return 0;
}
