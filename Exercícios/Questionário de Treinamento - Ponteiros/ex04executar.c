#include <stdio.h>

void funcl(int x){
     x =9 * x;
}

void func2 (int v[]){
v[0] = 9 * v[0];
}

void main (void){
    int x, v[2];

    x = 111;
    v[0] = 111;
    funcl(x);
    printf ("x: %d\n", x);
    func2(v);
    printf ("v[0]: %d\n", v[0]);
}
