#include <stdio.h>
#include <string.h>
int main() {
    char mainStr[100], subStr[100];
    int count[256] = {0};
    int i;
    printf("Enter main string: ");
    scanf("%99s", mainStr);
    printf("Enter substring: ");
    scanf("%99s", subStr);
    if (strlen(mainStr) != strlen(subStr)) {
        printf("Not an anagram\n");
        return 0;
    }
    for (i = 0; mainStr[i] != '\0'; i++) {
        count[(unsigned char)mainStr[i]]++;
        count[(unsigned char)subStr[i]]--;
    }
    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("Not an anagram\n");
            return 0;
        }
    }
    printf("Anagram\n");
    return 0;
}