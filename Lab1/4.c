#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int left = 0, right;
    int palindrome = 1;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    right = strlen(str) - 1;
    if (str[right] == '\n') {
        str[right] = '\0';
        right--;
    }
    while (left < right) {
        if (str[left] == ' ') {
            left++;
            continue;
        }
        if (str[right] == ' ') {
            right--;
            continue;
        }
        if (tolower(str[left]) != tolower(str[right])) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}