#include <stdio.h>

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    for(int i = 0; i < n1; i++)
        printf("%d ", v1[i]);
    printf("\n");
    return 0;
}

