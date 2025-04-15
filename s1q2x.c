#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1), temp;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  
    }
}

int main() {
    int n_values[] = {1000, 5000, 10000, 20000}; 
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    srand(time(0)); 

    for (int t = 0; t < num_tests; t++) {
        int n = n_values[t];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("n = %d\tTime taken = %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}
