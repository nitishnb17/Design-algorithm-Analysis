// Day 3

// Given an array of daily temperatures, find the length of the longest consecutive strictly increasing streak.


// Input:  [10, 12, 15, 14, 16, 18, 20]
// Output: 4

// Explanation: 14, 16, 18, 20 is the longest increasing streak.
// #include <stdio.h>

int longestIncreasingStreak(int arr[], int n) {
    // Edge cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int maxLen = 1;
    int curLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;              // streak continues
        } else {
            curLen = 1;            // streak breaks, reset
        }

        if (curLen > maxLen)
            maxLen = curLen;
    }

    return maxLen;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Longest increasing streak length: 0\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = longestIncreasingStreak(arr, n);
    printf("Longest increasing streak length: %d\n", result);

    return 0;
}