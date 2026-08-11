#include <stdio.h>

int main() {
    int n;

    printf("Enter size of matrices (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];
    long long multiplication_count = 0;

    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;

            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
                multiplication_count++;
            }
        }
    }
    printf("\nResultant Matrix C = A x B:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    printf("\nTotal number of multiplication operations = %lld\n",
           multiplication_count);

    printf("Time Complexity = O(n^3)\n");

    return 0;
}