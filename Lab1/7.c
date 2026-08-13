#include <stdio.h>
#include <time.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    clock_t start = clock();

    int arr[1000];
    int n, k;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    // If K is greater than n
    k = k % n;

    // Reverse entire array
    reverse(arr, 0, n - 1);

    // Reverse first K elements
    reverse(arr, 0, k - 1);

    // Reverse remaining elements
    reverse(arr, k, n - 1);

    printf("\nArray after right rotation:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t end = clock();

    printf("\n\nExecution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}