#include <stdio.h> // fopen, fclose, fscanf, printf

#define DIM 9

struct Configuratie {
    int tabla[DIM][DIM];
    int solutie[DIM][DIM];
    int zone[DIM][DIM];
};

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
    struct Configuratie config;
    FILE *f = fopen("date.in", "r");
    if(f == NULL) {
        printf("Eroare deschidere fisier de intrare\n");
        return 1;
    }
    citeste_matrice(f, config.tabla);
    citeste_matrice(f, config.zone);
    fclose(f);

    afiseaza_matrice(config.tabla);
    afiseaza_matrice(config.zone);
    return 0;
}

