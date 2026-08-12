// Question of Day 2
// Write a program using a while loop that repeatedly asks the user to enter the password and
// stops only when the correct password is entered. Finally, display "Login successful!".
#include <stdio.h>
#include <string.h>

int main() {
    char pass[50];
    char password[50];

    printf("Enter a new Password:\n");
    scanf("%49s", pass);

    printf("Enter Password:\n");
    scanf("%49s", password);

    while (strcmp(pass, password) != 0) {
        printf("Enter Password:\n");
        scanf("%49s", password);
    }

    printf("Login successful!\n");
    return 0;
}