#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    clock_t start = clock();

    char str[1000];
    int left = 0, right;
    int palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    right = strlen(str) - 1;

    // Remove newline
    if (str[right] == '\n')
        right--;

    while (left < right) {

        // Ignore spaces
        if (str[left] == ' ') {
            left++;
            continue;
        }

        if (str[right] == ' ') {
            right--;
            continue;
        }

    // Compare ignoring case
        if (tolower((unsigned char)str[left]) !=
            tolower((unsigned char)str[right])) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if (palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    clock_t end = clock();
    printf("Execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}