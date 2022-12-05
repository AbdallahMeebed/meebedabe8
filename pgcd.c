#include <stdio.h>

int pgcd(int a, int b);

int main(){
    int a = 2345;
    int b = 25;

    printf("PGCD: %i", pgcd(b, a));
    return 0;
}

int pgcd(int a, int b){
    if (a >= b){
        if (b == 0) return a;
        return pgcd(b, b % a);
    }
    return pgcd(b, a);
}