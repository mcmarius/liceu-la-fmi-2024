#include <iostream> // std::cout
#include <fstream>  // std::ifstream

using namespace std;

#define DIM 9

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
    int tabla_initiala[DIM][DIM], tabla_completa[DIM][DIM], zone[DIM][DIM];
    ifstream f("date.in");
    if(!f.is_open()) {
        cout << "Eroare deschidere fisier de intrare\n";
        return 1;
    }
    citeste_matrice(f, tabla_initiala);
    citeste_matrice(f, zone);
    f.close();

    afiseaza_matrice(tabla_initiala);
    afiseaza_matrice(zone);
    return 0;
}

