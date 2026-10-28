#include <stdio.h>
int main() {
    int n;
    int ones = 0, zeros = 0;
    int current = 0, maxConsecutive = 0;
    int bit;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0) {
        bit = n % 2;
        if (bit == 1) {
            ones++;
            current++;
            if (current > maxConsecutive)
                maxConsecutive = current;
        } 
        else {
            zeros++;
            current = 0;
        }
        n = n / 2;
    }
    printf("a. Number of 1 = %d and Number of 0 = %d\n", ones, zeros);
    printf("b. Consecutive 1 = %d\n", maxConsecutive);
    return 0;
}