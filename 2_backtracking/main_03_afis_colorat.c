#include <stdio.h>  // fopen, fclose, fscanf, printf
#include "rlutil.h" // setColor, saveDefaultColor, resetColor, WHITE

#define DIM 9
#define CELL_SIZE 3

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

void afiseaza_joc(struct Configuratie *config);

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

    afiseaza_joc(&config);
    return 0;
}

void afiseaza_joc(struct Configuratie *config) {
    saveDefaultColor();
    for(int i = 0; i < DIM; i++) {
        if(i % CELL_SIZE == 0) {
            // linia de sus
            printf("\n");
            setColor(WHITE);
            for(int j = 0; j < 2 * (DIM + CELL_SIZE) + 1; j++)
                printf("-");
        }
        printf("\n");
        for(int j = 0; j < DIM; j++) {
            if(j % CELL_SIZE == 0) {
                setColor(WHITE);
                printf("| "); // linii verticale stanga si mijloc
            }
            setColor(config->zone[i][j]);
            printf("%d ", config->tabla[i][j]);
        }
        setColor(WHITE);
        printf("|");  // linia din capat dreapta
    }
    // linia de jos
    printf("\n");
    for(int j = 0; j < 2 * (DIM + CELL_SIZE) + 1; j++)
        printf("-");
    printf("\n");
    resetColor();
    // Exercitiu: folositi biblioteca libfort pentru afisare
    // https://github.com/seleznevae/libfort
    // Exercitiu: afisati delimitarile pe zone, nu pe celule
}

