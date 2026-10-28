#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char s[]) {
    int n = strlen(s);
    int left = 0, maxLength = 0;
    int lastSeen[256];
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }
    for (int right = 0; right < n; right++) {
        unsigned char ch = s[right];
        if (lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1;
        }
        lastSeen[ch] = right;
        int length = right - left + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;}
int main() {
    char s[1000];
    scanf("%999s", s);
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}