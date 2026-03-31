#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct horario Horario;
typedef struct data Data;
typedef struct compromisso Compromisso;

struct horario{
    int hora;
    int minuto;
    int segundo;
};

struct data{
    int dia;
    int mes;
    int ano;
};

struct compromisso{
    Horario horario;
    Data data;
    char descricao[100];
};

void imprimeCompromisso (Compromisso comp, int i){
    printf("\nCompromisso %d\n", i+1);
    printf("Data: %d/%d/%d\n", comp.data.dia, comp.data.mes, comp.data.ano);
    printf("Horário: %d:%d:%d\n", comp.horario.hora, comp.horario.minuto, comp.horario.segundo);
    printf("Descrição: %s\n", comp.descricao);
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int i = 0, n = 5, j;
    int totCompromissos, mesCompromisso;
    char continuar;
    Horario hora;
    Data data;
    Compromisso compromisso[n];

    printf("------- CADASTRO DE COMPROMISSOS -------\n");

    do{
       printf("Hora: ");
       scanf("%d", &compromisso[i].horario.hora);
       printf("Minuto: ");
       scanf("%d", &compromisso[i].horario.minuto);
       printf("Segundo: ");
       scanf("%d", &compromisso[i].horario.segundo);
       printf("Dia: ");
       scanf("%d", &compromisso[i].data.dia);
       printf("Mês: ");
       scanf("%d", &compromisso[i].data.mes);
       printf("Ano: ");
       scanf("%d", &compromisso[i].data.ano);
       printf("Descrição do compromisso: ");
       scanf(" %[^\n]", compromisso[i].descricao);
       printf("Deseja cadastrar mais um compromisso?\n");
       scanf(" %c", &continuar);
       i++;

    }while(continuar == 'S' || continuar == 's');

    totCompromissos = i;

    do{
        printf("Mostrar os compromissos do mês: ");
        scanf("%d", &mesCompromisso);
        j = 0;
        for(i = 0; i< totCompromissos;i++){
            if(mesCompromisso == compromisso[i].data.mes){
                imprimeCompromisso(compromisso[i], i);
                j++;
            }
        }
        if(j == 0){
            printf("\nNenhum compromisso marcado para esse mês.\n");
        }
        printf("Deseja fazer outra busca?\n");
        scanf(" %c", &continuar);
    }while(continuar == 'S' || continuar == 's');
}
