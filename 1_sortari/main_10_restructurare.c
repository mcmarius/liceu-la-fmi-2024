#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand, malloc, free
#include <time.h>   // time, clock, CLOCKS_PER_SEC

#define NMAX_AFIS 100

void afis(int *v, int n) {
    for(int i = 0; i < n; i++)
        if(i < NMAX_AFIS)
            printf("%d ", v[i]);
    if(n > NMAX_AFIS)
        printf("...");
    printf("\n----------\n");
}

void genereaza_valori_aleatoare(int *v, int n, int val_min, int val_max) {
    double t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++)
        v[i] = rand() % (val_max - val_min + 1) + val_min;
    t2 = clock();
    printf("Timp generare %d numere: %lf secunde\n", n, 1.0*(t2 - t1) / CLOCKS_PER_SEC);
}

void rezolva_problema(int n, int val_min, int val_max) {
    int *v = malloc(sizeof(*v) * n);
    genereaza_valori_aleatoare(v, n, val_min, val_max);
    afis(v, n);
    free(v);
}

int main() {
    srand(time(NULL));
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    printf("----------\n");
    afis(v1, n1);
    //
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    afis(v2, n2);
    //
    int n3 = 100000;
    rezolva_problema(n3, 12, 34);
    //
    int n4 = 1000000;
    rezolva_problema(n4, 12, 34);
    //
    int n5 = 10000000;
    rezolva_problema(n5, 12, 34);
    return 0;
}

