#include <stdio.h>
int main() {
    int broj, suma;
    for(suma=0;suma<=100;){
        printf("Unesite broj: ");
        scanf("%d", &broj);
        suma+=broj;
    }
    printf("Suma je: %d", suma);
    return 0;
}

