#include <iostream>

using namespace std; // ATENTIE!! Complet GRESIT in fisiere header

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    for(int i = 0; i < n1; i++)
        cout << v1[i] << " ";
    cout << "\n";
    return 0;
}

