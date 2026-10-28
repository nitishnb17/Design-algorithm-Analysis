// Question of Day 2
// Write a program using a while loop that repeatedly asks the user to enter the password and stops only when the correct password is entered. Finally, display "Login successful!".
// Here is a C program that implements the requested functionality using a while loop:
// ```c
#include <stdio.h>
#include <string.h>
int main() {
    const char correctPassword[] = "Aarav123"; // Set the correct password
    char inputPassword[50]; // Buffer to store user input

    while (1) { // Infinite loop until the correct password is entered
        printf("Enter the password: ");
        scanf("%s", inputPassword); // Read user input

        if (strcmp(inputPassword, correctPassword) == 0) { // Check if the input matches the correct password
            printf("Login successful!\n");
            break; // Exit the loop if the password is correct
        } else {
            printf("Incorrect password. Please try again.\n");
        }
    }
    return 0;
}