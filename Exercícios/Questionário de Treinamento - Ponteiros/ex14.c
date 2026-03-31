#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void concatenaString(char *sa, char *sb){
    int count = 0;
    while(*sa){
        count++;
        sa++;
    }

    while(*sb){
        *sa = *sb;
        sb++;
        sa++;
    }
    *sa = '\0';
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    char str1[50] = "Boa noite";//sempre que for concatenar duas strings setar o tamanho da primeira pra não estourar o buffer de mem.
    char str2[] = " tudo bem?";

    concatenaString(str1, str2);
    printf("%s", str1);
}
