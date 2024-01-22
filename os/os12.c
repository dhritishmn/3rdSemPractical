#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4 // Number of threads

// Structure to pass arguments to the thread function
struct ThreadData {
    int *numbers;
    int start;
    int end;
    long long sum;
};

// Thread function to calculate the sum of a subset of numbers
void *calculateSum(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    data->sum = 0;

    // Calculate the sum for the assigned subset of numbers
    for (int i = data->start; i < data->end; ++i) {
        data->sum += data->numbers[i];
    }

    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *numbers = (int *)malloc(n * sizeof(int));
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    pthread_t threads[MAX_THREADS];
    struct ThreadData threadData[MAX_THREADS];

    int elementsPerThread = n / MAX_THREADS;
    int remainingElements = n % MAX_THREADS;

    // Create threads and assign tasks
    for (int i = 0; i < MAX_THREADS; ++i) {
        threadData[i].numbers = numbers;
        threadData[i].start = i * elementsPerThread;
        threadData[i].end = (i == MAX_THREADS - 1) ? (i + 1) * elementsPerThread + remainingElements : (i + 1) * elementsPerThread;

        pthread_create(&threads[i], NULL, calculateSum, (void *)&threadData[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Aggregate results from all threads
    long long totalSum = 0;
    for (int i = 0; i < MAX_THREADS; ++i) {
        totalSum += threadData[i].sum;
    }

    printf("Sum of %d numbers: %lld\n", n, totalSum);

    free(numbers);

    return 0;
}
