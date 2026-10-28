#include <stdio.h>
int main() {
    int a[] = {0, 1, 0, 3, 12};
    int n = 5;
    int temp[5];
    int j = 0;
    // Store non-zero elements
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp[j++] = a[i];
        }
    }
    // Fill remaining positions with zero
    while (j < n) {
        temp[j++] = 0;
    }
    printf("Array after shifting zeros: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    return 0;
}