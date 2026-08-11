#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linearsearch()
{
    int key, n, found = 0;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched:\n");
    scanf("%d", &key);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    printf("Execution time = %lf seconds\n", cpu_time_used);
}

void binarysearch()
{
    int key, n, found = 0;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the sorted elements of the array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched:\n");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    int mid;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    printf("Execution time = %lf seconds\n", cpu_time_used);
}

int main()
{
    int choice;

    do
    {
        printf("\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            linearsearch();
        }
        else if (choice == 2)
        {
            binarysearch();
        }
        else if (choice == 3)
        {
            printf("Exiting program\n");
        }
        else
        {
            printf("Invalid input.\n");
        }

    } while (choice != 3);

    return 0;
}