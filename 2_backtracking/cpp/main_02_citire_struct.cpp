#include <iostream> // std::cout
#include <fstream>  // std::ifstream

using namespace std;

#define DIM 9

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

void afiseaza_matrice(int tabla[DIM][DIM]) {
    cout << "----------\n";
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++)
            cout << tabla[i][j] << " ";
        cout << "\n";
    }
    cout << "----------\n";
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

    afiseaza_matrice(config.tabla);
    afiseaza_matrice(config.zone);
    return 0;
}

