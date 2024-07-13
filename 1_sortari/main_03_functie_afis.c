#include <stdio.h>

void afis(int *v, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n----------\n");
}

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    printf("----------\n");
    afis(v1, n1);
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    afis(v2, n2);
    return 0;
}

