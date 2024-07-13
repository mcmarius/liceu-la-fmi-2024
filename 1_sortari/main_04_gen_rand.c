#include <stdio.h>
#include <stdlib.h>

void afis(int *v, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n----------\n");
}

void genereaza_valori_aleatoare(int *v, int n) {
    for(int i = 0; i < n; i++)
        v[i] = rand();
}

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    printf("----------\n");
    afis(v1, n1);
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    afis(v2, n2);
    int v3[10] = {0};
    int n3 = sizeof(v3) / sizeof(v3[0]);
    genereaza_valori_aleatoare(v3, n3);
    afis(v3, n3);
    return 0;
}

