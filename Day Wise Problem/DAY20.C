#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    int lastSeen[256];
    int left = 0, maxLength = 0, start = 0;
    printf("Enter a string: ");
    scanf("%999s", s);
    for (int i = 0; i < 256; i++)
        lastSeen[i] = -1;
    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char ch = s[right];
        if (lastSeen[ch] >= left)
            left = lastSeen[ch] + 1;
        lastSeen[ch] = right;
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }
    }
    printf("Longest substring: ");
    for (int i = start; i < start + maxLength; i++)
        printf("%c", s[i]);
    printf("\nLength: %d\n", maxLength);
    return 0;
}