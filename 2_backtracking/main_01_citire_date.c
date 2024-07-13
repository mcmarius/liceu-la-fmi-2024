#include <stdio.h> // fopen, fclose, fscanf, printf

#define DIM 9

void citeste_matrice(FILE* f, int tabla[DIM][DIM]) {
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            fscanf(f, "%d", &tabla[i][j]);
}

void afiseaza_matrice(int tabla[DIM][DIM]) {
    printf("----------\n");
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++)
            printf("%d ", tabla[i][j]);
        printf("\n");
    }
    printf("----------\n");
}

int main() {
    int tabla_initiala[DIM][DIM], tabla_completa[DIM][DIM], zone[DIM][DIM];
    FILE *f = fopen("date.in", "r");
    if(f == NULL) {
        printf("Eroare deschidere fisier de intrare\n");
        return 1;
    }
    citeste_matrice(f, tabla_initiala);
    citeste_matrice(f, zone);
    fclose(f);

    afiseaza_matrice(tabla_initiala);
    afiseaza_matrice(zone);
    return 0;
}

