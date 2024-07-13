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

void rezolva(struct Configuratie *config, int linie, int coloana) {
    afiseaza_joc(config);
    // de la valoarea minima la valoarea maxima
    for(int val = 1; val <= 9; val++) {
        if(config->tabla[linie][coloana] == 0) {
            // nu vrem sa suprascriem configuratia initiala
            // pentru elementul curent, incercam fiecare valoare posibila
            config->solutie[linie][coloana] = val;
        }
        // dupa ce am completat elementul curent, avansam la elementul urmator
        if(coloana < DIM - 1)
            coloana++;
        else {
            coloana = 0;
            linie++;
        }
        // continuam pana la ultima linie
        // daca linie >= DIM, inseamna ca am terminat de completat
        if(linie < DIM)
            rezolva(config, linie, coloana);
    }
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

    // copiem datele in matricea cu datele pentru solutie
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            config.solutie[i][j] = config.tabla[i][j];

    printf("Configuratia initiala:");
    afiseaza_joc(&config);
    rezolva(&config, 0, 0);
    printf("\nConfiguratia finala:");
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
            printf("%d ", config->solutie[i][j]);
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

