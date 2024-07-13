#include <iostream> // std::cout
#include <fstream>  // std::ifstream
#include "rlutil.h" // rlutil::setColor, rlutil::saveDefaultColor, rlutil::resetColor, rlutil::WHITE

using namespace std;

#define DIM 9
#define CELL_SIZE 3

struct Configuratie {
    int tabla[DIM][DIM];
    int solutie[DIM][DIM];
    int zone[DIM][DIM];
};

void citeste_matrice(ifstream& f, int tabla[DIM][DIM]) {
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            f >> tabla[i][j];
}

void afiseaza_joc(Configuratie *config);

int unic_pe_linie(Configuratie *config, int linie, int coloana) {
    for(int i = 0; i < DIM; i++)
        if(i != coloana && config->solutie[linie][i] == config->solutie[linie][coloana])
            return 0;
    return 1;        
}

int configuratie_valida(Configuratie *config, int linie, int coloana) {
    // vrem sa vedem daca noul element completat respecta toate conditiile partiale
    return unic_pe_linie(config, linie, coloana);
}

int configuratie_completa(Configuratie *config, int linie, int coloana) {
    (void)config;
    return coloana == DIM - 1 && linie == DIM - 1;
}

void rezolva(Configuratie *config, int linie, int coloana) {
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
        // resetam la valoarea anterioara
        // aici nu conteaza, dar in alte probleme de bkt este nevoie sa restauram starea anterioara
        if(config->tabla[linie][coloana] == 0) {
            config->solutie[linie][coloana] = 0;
        }
    }
}

int main() {
    Configuratie config;
    ifstream f("date.in");
    if(!f.is_open()) {
        cout << "Eroare deschidere fisier de intrare\n";
        return 1;
    }
    citeste_matrice(f, config.tabla);
    citeste_matrice(f, config.zone);
    f.close();

    // copiem datele in matricea cu datele pentru solutie
    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            config.solutie[i][j] = config.tabla[i][j];

    cout << "Configuratia initiala:";
    afiseaza_joc(&config);
    rezolva(&config, 0, 0);
    cout << "\nConfiguratia finala:";
    afiseaza_joc(&config);
    return 0;
}

void afiseaza_joc(Configuratie *config) {
    rlutil::saveDefaultColor();
    for(int i = 0; i < DIM; i++) {
        if(i % CELL_SIZE == 0) {
            // linia de sus
            cout << "\n";
            rlutil::setColor(rlutil::WHITE);
            for(int j = 0; j < 2 * (DIM + CELL_SIZE) + 1; j++)
                cout << "-";
        }
        cout << "\n";
        for(int j = 0; j < DIM; j++) {
            if(j % CELL_SIZE == 0) {
                rlutil::setColor(rlutil::WHITE);
                cout << "| "; // linii verticale stanga si mijloc
            }
            rlutil::setColor(config->zone[i][j]);
            cout << config->solutie[i][j] << " ";  // Am modificat aici <<<<<<<<<<<<
        }
        rlutil::setColor(rlutil::WHITE);
        cout << "|";  // linia din capat dreapta
    }
    // linia de jos
    cout << "\n";
    for(int j = 0; j < 2 * (DIM + CELL_SIZE) + 1; j++)
        cout << "-";
    cout << "\n";
    rlutil::resetColor();
    // Exercitiu: folositi biblioteca libfort pentru afisare
    // https://github.com/seleznevae/libfort
    // Exercitiu: afisati delimitarile pe zone, nu pe celule
}

