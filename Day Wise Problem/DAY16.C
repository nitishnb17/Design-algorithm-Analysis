#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char password[101];
        scanf("%s", password);

        int lower = 0;
        int upper = 0;
        int digit = 0;
        int special = 0;

        int len = strlen(password);

        for (int i = 0; i < len; i++) {

            // Lowercase letter
            if (password[i] >= 'a' && password[i] <= 'z') {
                lower = 1;
            }

            // Uppercase letter strictly inside
            if (i > 0 && i < len - 1 &&
                password[i] >= 'A' && password[i] <= 'Z') {
                upper = 1;
            }

            // Digit strictly inside
            if (i > 0 && i < len - 1 &&
                password[i] >= '0' && password[i] <= '9') {
                digit = 1;
            }

            // Special character strictly inside
            if (i > 0 && i < len - 1 &&
                (password[i] == '@' ||
                 password[i] == '#' ||
                 password[i] == '%' ||
                 password[i] == '&' ||
                 password[i] == '?')) {
                special = 1;
            }
        }

        // Check all conditions
        if (lower && upper && digit && special && len >= 10)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}