#include <stdio.h>
#include <time.h>

#define SUBJECTS 5
#define MAX 100

struct Student {
    int roll;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float percentage;
    char grade;
};

int main() {
    clock_t start = clock();

    struct Student s[MAX];
    int n;
    int i, j;

    int topper = 0;
    float classAverage = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student data
    for (i = 0; i < n; i++) {

        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        printf("Enter marks of 5 subjects:\n");

        for (j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);

            s[i].total += s[i].marks[j];
        }

        // Calculate percentage
        s[i].percentage = s[i].total / 5.0;

        // Calculate grade
        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else if (s[i].percentage >= 50)
            s[i].grade = 'E';
        else
            s[i].grade = 'F';

        // Find topper
        if (s[i].percentage > s[topper].percentage)
            topper = i;

        classAverage += s[i].percentage;
    }

    classAverage /= n;

    // Display results
    printf("\n========== STUDENT RESULTS ==========\n");

    for (i = 0; i < n; i++) {

        printf("\nRoll Number : %d", s[i].roll);
        printf("\nName        : %s", s[i].name);
        printf("\nTotal       : %d / 500", s[i].total);
        printf("\nPercentage  : %.2f%%", s[i].percentage);
        printf("\nGrade       : %c\n", s[i].grade);
    }

    // Class topper
    printf("\n========== CLASS TOPPER ==========\n");
    printf("Roll Number : %d\n", s[topper].roll);
    printf("Name        : %s\n", s[topper].name);
    printf("Percentage  : %.2f%%\n", s[topper].percentage);

    // Failed students
    printf("\n========== FAILED STUDENTS ==========\n");

    int failed = 0;

    for (i = 0; i < n; i++) {

        for (j = 0; j < SUBJECTS; j++) {

            if (s[i].marks[j] < 33) {
                printf("%d - %s\n", s[i].roll, s[i].name);
                failed = 1;
                break;
            }
        }
    }

    if (!failed)
        printf("No student failed in any subject.\n");

    // Class average
    printf("\nClass Average: %.2f%%\n", classAverage);

    clock_t end = clock();

    printf("\nExecution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}