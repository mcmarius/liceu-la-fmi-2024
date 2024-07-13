#include <iostream>
#include <cstdlib>
#include <ctime>

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
    // printf("Timp generare %d numere: %lf secunde\n", n, 1.0*(t2 - t1) / CLOCKS_PER_SEC);
    cout << "Timp generare " << n << " numere: " <<  1.0*(t2 - t1) / CLOCKS_PER_SEC << " secunde\n";
}

int main() {
    srand(time(NULL));
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    cout << "----------\n";
    afis(v1, n1);
    //
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    afis(v2, n2);
    //
    // int v3[1'00'000] = {0};  // GCC 12, din C23
    int v3[100000] = {0};
    int n3 = sizeof(v3) / sizeof(v3[0]);
    genereaza_valori_aleatoare(v3, n3, 12, 34);
    afis(v3, n3);
    //
    int v4[1000000] = {0};
    int n4 = sizeof(v4) / sizeof(v4[0]);
    genereaza_valori_aleatoare(v4, n4, 12, 34);
    afis(v4, n4);
    return 0;
}

