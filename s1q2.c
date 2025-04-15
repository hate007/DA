#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int low, int high);int partition(int arr[], int low, int high);
void swap(int* a, int* b);
double time_elapsed(struct timespec start, struct timespec end);
int main() {
int n, i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];

srand(time(0));
for (i = 0; i < n; i++) {
arr[i] = rand() % 1000; 
}

struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);

quickSort(arr, 0, n - 1);

clock_gettime(CLOCK_MONOTONIC, &end);
printf("Sorted array: ");for (i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
printf("Time taken by Quick Sort: %lf seconds\n", time_elapsed(start, end));
return 0;
}

void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}

int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
if (arr[j] < pivot) {
i++;
swap(&arr[i], &arr[j]);
}}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}

void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}

double time_elapsed(struct timespec start, struct timespec end) {
double t;
t = (end.tv_sec - start.tv_sec) * 1e9;
t = (t + (end.tv_nsec - start.tv_nsec)) * 1e-9;
return t;
}