#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    int arr[1000];
    int n, target;
    int i, j;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("\nPairs whose sum is %d:\n", target);

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No pair found.\n");

    clock_t end = clock();

    printf("\nExecution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}