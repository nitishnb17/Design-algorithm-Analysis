#include <stdio.h>
int main() {
    int a[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2, temp;
    if (k < 1 || k > n) {
        printf("Invalid k\n");
        return 0;
    }
    // Sort in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Kth largest element: %d\n", a[k - 1]);
    return 0;
}