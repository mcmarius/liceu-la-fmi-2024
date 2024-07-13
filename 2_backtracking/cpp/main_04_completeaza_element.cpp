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

void rezolva(Configuratie *config, int linie, int coloana) {
    // de la valoarea minima la valoarea maxima
    for(int val = 1; val <= 9; val++)
        if(config->tabla[linie][coloana] == 0) // nu vrem sa suprascriem configuratia initiala
            config->solutie[linie][coloana] = val; // pentru elementul curent, incercam fiecare valoare posibila
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

