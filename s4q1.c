#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
// Create temporary arrays
int L[n1], R[n2];
// Copy data to temporary arrays L[] and R[]
for (i = 0; i < n1; i++)
L[i] = arr[l + i];for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
// Merge the temporary arrays back into arr[l..r]
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
// Copy the remaining elements of L[], if there are any
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
// Copy the remaining elements of R[], if there are any
while (j < n2) {
arr[k] = R[j];
j++;
k++;}
}
// Merge sort function
void mergeSort(int arr[], int l, int r) {
if (l < r) {
// Find the middle point
int m = l + (r - l) / 2;
// Sort first and second halves
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
// Merge the sorted halves
merge(arr, l, m, r);
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
// Allocate memory for the array
int *arr = (int *)malloc(n * sizeof(int));
// Input the elements
printf("Enter %d elements:\n", n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
// Record start time
clock_t start = clock();// Perform merge sort
mergeSort(arr, 0, n - 1);
// Record end time
clock_t end = clock();
// Calculate the time taken
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
// Output the sorted array
printf("Sorted array:\n");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
// Output the time taken
printf("Time taken: %f seconds\n", time_taken);
// Free dynamically allocated memory
free(arr);
return 0;
}