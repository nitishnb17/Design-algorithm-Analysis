#include <stdio.h>
#include <time.h>

int main(void)
{
    unsigned long long number;

    printf("Enter a non-negative integer: ");

    if (scanf("%llu", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Start measuring algorithm execution time */
    clock_t startTime = clock();

    int ones = 0;
    int zeros = 0;
    int currentOnes = 0;
    int maximumConsecutiveOnes = 0;

    if (number == 0) {
        zeros = 1;  /* Binary representation of 0 is "0" */
    } else {
        unsigned long long value = number;

        while (value != 0) {
            if ((value & 1ULL) != 0) {
                ones++;
                currentOnes++;

                if (currentOnes > maximumConsecutiveOnes) {
                    maximumConsecutiveOnes = currentOnes;
                }
            } else {
                zeros++;
                currentOnes = 0;
            }

            value >>= 1;
        }
    }

    /* Stop measuring execution time */
    clock_t endTime = clock();

    double executionTime =
        (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Maximum consecutive 1s: %d\n",
           maximumConsecutiveOnes);

    printf("Execution time: %.9f seconds\n", executionTime);
    printf("Execution time: %.6f milliseconds\n",
           executionTime * 1000.0);

    return 0;
}