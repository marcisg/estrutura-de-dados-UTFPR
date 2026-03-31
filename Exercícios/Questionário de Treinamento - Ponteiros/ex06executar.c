#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime (char *s, int n){
    char *c;
    for(c = s; c < s +n; c++){
        printf ("%c", *c);
    }
}

int main(void){
    char s[] = "bom dia";
    imprime(s, strlen(s));
}
