// Day1:  
// Write a C program that accepts a positive integer containing digits from 0 to 9. Exactly one digit is missing, while the remaining nine digits appear exactly once. 
// Input : 854102967
// Output:  3

#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    int sum = 0;
    
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    
    printf("%d\n", 45 - sum);
    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(1)