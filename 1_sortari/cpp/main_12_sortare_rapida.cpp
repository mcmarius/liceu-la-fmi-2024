#include <iostream> // std::cout
#include <cstdlib>  // std::rand, std::srand, std::malloc, std::free, std::qsort
#include <ctime>    // std::time, std::clock, CLOCKS_PER_SEC

using namespace std;

#define NMAX_AFIS 100

void afis(int *v, int n) {
    for(int i = 0; i < n; i++)
        if(i < NMAX_AFIS)
            cout << v[i] << " ";
    if(n > NMAX_AFIS)
        cout <<"...";
    cout << "\n----------\n";
}

void genereaza_valori_aleatoare(int *v, int n, int val_min, int val_max) {
    double t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++)
        v[i] = rand() % (val_max - val_min + 1) + val_min;
    t2 = clock();
    cout << "Timp generare " << n << " numere: " <<  1.0*(t2 - t1) / CLOCKS_PER_SEC << " secunde\n";
}

/*void sorteaza_lent(int *v, int n) {
    double t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    t2 = clock();
    // printf("Timp sortare lenta %d numere: %lf secunde\n", n, 1.0*(t2 - t1) / CLOCKS_PER_SEC);
    cout << "Timp sortare lenta " << n << " numere: " <<  1.0*(t2 - t1) / CLOCKS_PER_SEC << " secunde\n";
}*/

int compara_numere(const void *elem1, const void *elem2) {
    int nr1 = *(int *)elem1;
    int nr2 = *(int *)elem2;
    if(nr1 < nr2)
        return -1;
    if(nr1 > nr2)
        return 1;
    return 0;
}

void rezolva_problema(int n, int val_min, int val_max) {
    // int *v = (int*) malloc(sizeof(*v) * n);
    int *v = new int[n];
    genereaza_valori_aleatoare(v, n, val_min, val_max);
    // sorteaza_lent(v, n);
    // genereaza_valori_aleatoare(v, n, val_min, val_max);
    double t1, t2;
    t1 = clock();
    qsort(v, n, sizeof(v[0]), &compara_numere);
    t2 = clock();
    // printf("Timp sortare rapida %d numere: %lf secunde\n", n, 1.0*(t2 - t1) / CLOCKS_PER_SEC);
    cout << "Timp sortare rapida " << n << " numere: " <<  1.0*(t2 - t1) / CLOCKS_PER_SEC << " secunde\n";
    afis(v, n);
    // free(v);
    delete[] v;
}

int main() {
    srand(time(NULL));
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    printf("----------\n");
    afis(v1, n1);
    //
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    afis(v2, n2);
    //
    int n3 = 1000;
    rezolva_problema(n3, 12, 34567);
    //
    int n4 = 10000;
    rezolva_problema(n4, 12, 34567);
    //
    int n5 = 20000;
    // int n5 = 100000;
    rezolva_problema(n5, 12, 34567);
    //
    int n6 = 30000;
    // int n6 = 1000000;
    rezolva_problema(n6, 12, 34567);
    //
    int n7 = 40000;
    // int n7 = 10000000;
    rezolva_problema(n7, 12, 34567);
    //
    int n8 = 50000;
    // int n8 = 100000000;
    rezolva_problema(n8, 12, 34567);
    /*
    Exercitii:
    - rescrieti functia rezolva_problema astfel incat sa primeasca un vector de valori pentru n si sa intoarca un vector de timpi
    - pentru fiecare valoare a lui n, rulati codul de 5-10 ori pentru a face o medie; datele trebuie generate din nou la fiecare pas, altfel sortarea nu este
    - cititi datele de intrare din fisier
    - scrieti datele de iesire in alt fisier
    - sortati structuri in loc de numere dupa diverse criterii
    - folositi instructiuni assert pentru a verifica rezultatele pe datele de iesire
    */
    return 0;
}

