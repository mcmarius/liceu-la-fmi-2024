#include <stdio.h>  // fopen, fclose, fscanf, printf
#include <stdlib.h> // exit
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

int unic_pe_linie(struct Configuratie *config, int linie, int coloana) {
    for(int i = 0; i < DIM; i++)
        if(i != coloana && config->solutie[linie][i] == config->solutie[linie][coloana])
            return 0;
    return 1;        
}

int unic_pe_coloana(struct Configuratie *config, int linie, int coloana) {
    for(int i = 0; i < DIM; i++)
        if(i != linie && config->solutie[i][coloana] == config->solutie[linie][coloana])
            return 0;
    return 1;        
}

int unic_pe_zona(struct Configuratie *config, int linie, int coloana) {
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++) {
            if(i != linie || j != coloana) {
                if(config->solutie[i][j] == config->solutie[linie][coloana] &&
                    config->zone[i][j] == config->zone[linie][coloana])
                    return 0;
            }
        }
    return 1;
}

int configuratie_valida(struct Configuratie *config, int linie, int coloana) {
    // vrem sa vedem daca noul element completat respecta toate conditiile partiale
    return unic_pe_linie(config, linie, coloana) &&
        unic_pe_coloana(config, linie, coloana) &&
        unic_pe_zona(config, linie, coloana);
}

int configuratie_completa(struct Configuratie *config, int linie, int coloana) {
    (void)config;
    return coloana == DIM - 1 && linie == DIM - 1;
}

void rezolva(struct Configuratie *config, int linie, int coloana) {
    // de la valoarea minima la valoarea maxima
    for(int val = 1; val <= 9; val++) {
        // nu vrem sa suprascriem configuratia initiala
        if(config->tabla[linie][coloana] == 0) {
            // pentru elementul curent, incercam fiecare valoare posibila
            config->solutie[linie][coloana] = val;
        }
        if(configuratie_valida(config, linie, coloana)) {
            // am ajuns la ultimul element, inseamna ca am terminat de completat
            // folosim o functie separata daca avem conditii mai complicate
            if(configuratie_completa(config, linie, coloana)) {
                afiseaza_joc(config);
                exit(0);
            }
            else {
                // altfel, continuam pana la ultima linie
                // dupa ce am completat elementul curent, avansam la elementul urmator
                if(coloana < DIM - 1)
                    rezolva(config, linie, coloana + 1);
                else
                    rezolva(config, linie + 1, 0);
            }
        }
        // resetam la valoarea anterioara la intoarcerea din backtracking
        if(config->tabla[linie][coloana] == 0) {
            config->solutie[linie][coloana] = 0;
        }
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

    // copiem datele initiale in matricea cu datele pentru solutie
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            config.solutie[i][j] = config.tabla[i][j];

    printf("Configuratia initiala:");
    afiseaza_joc(&config);
    rezolva(&config, 0, 0);
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

