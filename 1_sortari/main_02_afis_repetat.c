#include <stdio.h>

int main() {
    int v1[] = {18, 7, 2024, 10, 12};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    printf("----------\n");
    for(int i = 0; i < n1; i++)
        printf("%d ", v1[i]);
    printf("\n----------\n");
    int v2[] = {24, 7, 2024, 14, 16};
    int n2 = sizeof(v2) / sizeof(v2[0]);
    for(int i = 0; i < n2; i++)
        printf("%d ", v2[i]);
    printf("\n----------\n");
    return 0;
}

