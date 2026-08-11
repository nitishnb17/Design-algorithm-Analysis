#include <stdio.h>

int main() {
    int n, m;
    printf("Enter size of first array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of first sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter size of second array: ");
    scanf("%d", &m);
    int b[m];
    printf("Enter elements of second sorted array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    int c[n + m];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
    printf("\nMerged sorted array:\n");
    for (i = 0; i < n + m; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}