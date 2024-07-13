#include <iostream>

using namespace std; // ATENTIE!! Complet GRESIT in fisiere header

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    cout << "----------\n";
    for(int i = 0; i < n1; i++)
        cout << v1[i] << " ";
    cout << "\n----------\n";
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    for(int i = 0; i < n2; i++)
        cout << v2[i] << " ";
    cout << "\n----------\n";
    return 0;
}

