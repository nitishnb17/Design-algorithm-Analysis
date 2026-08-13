#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    int A[50][50], B[50][50], C[50][50];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Compatibility check
    if (c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }
    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    // Initialize result matrix
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }
    // Matrix multiplication
    for (i = 0; i < r1; i++) {
        for (k = 0; k < c1; k++) {
            for (j = 0; j < c2; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResult Matrix:\n");

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    clock_t end = clock();

    printf("\nExecution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}