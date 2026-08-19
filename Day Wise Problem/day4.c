#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long long key;
    size_t index;
    int occupied;
} HashEntry;

static size_t hashValue(long long key, size_t capacity)
{
    uint64_t value = (uint64_t)key;

    value ^= value >> 30;
    value *= UINT64_C(0xbf58476d1ce4e5b9);
    value ^= value >> 27;
    value *= UINT64_C(0x94d049bb133111eb);
    value ^= value >> 31;

    return (size_t)(value & (capacity - 1));
}

static size_t getCapacity(size_t arraySize)
{
    size_t capacity = 8;

    while (capacity < arraySize * 2) {
        capacity *= 2;
    }

    return capacity;
}

static int search(
    const HashEntry table[],
    size_t capacity,
    long long key,
    size_t *index
)
{
    size_t position = hashValue(key, capacity);

    while (table[position].occupied) {
        if (table[position].key == key) {
            *index = table[position].index;
            return 1;
        }

        position = (position + 1) & (capacity - 1);
    }

    return 0;
}

static void insert(
    HashEntry table[],
    size_t capacity,
    long long key,
    size_t index
)
{
    size_t position = hashValue(key, capacity);

    while (table[position].occupied) {
        /* Keep the first index of a duplicate value */
        if (table[position].key == key) {
            return;
        }

        position = (position + 1) & (capacity - 1);
    }

    table[position].key = key;
    table[position].index = index;
    table[position].occupied = 1;
}

static int twoSum(
    const long long array[],
    size_t size,
    long long target,
    size_t result[2]
)
{
    size_t capacity = getCapacity(size);
    HashEntry *table = calloc(capacity, sizeof(*table));

    if (table == NULL) {
        return -1;
    }

    for (size_t i = 0; i < size; i++) {
        long long required = target - array[i];
        size_t requiredIndex;

        if (search(table, capacity, required, &requiredIndex)) {
            result[0] = requiredIndex;
            result[1] = i;

            free(table);
            return 1;
        }

        insert(table, capacity, array[i], i);
    }

    free(table);
    return 0;
}

int main(void)
{
    size_t size;

    printf("Enter array size: ");

    if (scanf("%zu", &size) != 1 || size < 2) {
        printf("Invalid array size.\n");
        return 1;
    }

    long long *array = malloc(size * sizeof(*array));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %zu array elements: ", size);

    for (size_t i = 0; i < size; i++) {
        if (scanf("%lld", &array[i]) != 1) {
            printf("Invalid array element.\n");
            free(array);
            return 1;
        }
    }

    long long target;

    printf("Enter target: ");

    if (scanf("%lld", &target) != 1) {
        printf("Invalid target.\n");
        free(array);
        return 1;
    }

    size_t result[2];

    /* Start measuring two-sum execution time */
    clock_t startTime = clock();

    int status = twoSum(array, size, target, result);

    /* Stop measuring execution time */
    clock_t endTime = clock();

    double executionTime =
        (double)(endTime - startTime) / CLOCKS_PER_SEC;

    if (status == 1) {
        printf("Indices: [%zu, %zu]\n", result[0], result[1]);
    } else if (status == 0) {
        printf("No valid pair found.\n");
    } else {
        printf("Memory allocation failed.\n");
    }

    printf("Execution time: %.9f seconds\n", executionTime);
    printf("Execution time: %.6f milliseconds\n",
           executionTime * 1000.0);

    free(array);
    return 0;
}