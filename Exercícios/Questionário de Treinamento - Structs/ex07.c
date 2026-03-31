#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct coordenadaPolar Polar;
typedef struct planoCartesiano Cartesiano;

struct coordenadaPolar{
    float raio;
    float argumento;
};

struct planoCartesiano{
    float x;
    float y;
};

int main(){

    setlocale(LC_ALL,"Portuguese");

    Polar pontos;
    Cartesiano pontos2;

    printf("Insira um valor para o raio: ");
    scanf("%f", &pontos.raio);
    printf("Insira um argumento: ");
    scanf("%f", &pontos.argumento);

    pontos2.x = pontos.raio * cos(pontos.argumento);
    pontos2.y = pontos.raio * sin(pontos.argumento);

    printf("O resultado é %.4f para x e %.4f para y.", pontos2.x, pontos2.y);

}
