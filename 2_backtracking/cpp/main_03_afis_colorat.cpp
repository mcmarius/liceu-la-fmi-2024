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
            cout << config->tabla[i][j] << " ";
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

