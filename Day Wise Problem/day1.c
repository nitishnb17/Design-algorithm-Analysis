// Day1:  Write a C program that accepts a positive integer containing digits from 0 to 9. Exactly one digit is missing, while the remaining nine digits appear exactly once. Input : 854102967 Output:  3
#include <stdio.h>
int main() {
    long long n;
    int digit, sum = 45;

    printf("Enter the number: ");
    scanf("%lld", &n);

    while (n > 0) {
        digit = n % 10;
        sum = sum - digit;
        n = n / 10;
    }

    printf("Missing digit = %d\n", sum);

    return 0;
}