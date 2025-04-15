#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int largest = i; 
int l = 2 * i + 1; 
int r = 2 * i + 2; 

if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;
if (largest != i) {
int temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
for (int i = n - 1; i > 0; i--) {
int temp = arr[0];arr[0] = arr[i];
arr[i] = temp;
heapify(arr, i, 0);
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int));
srand(time(NULL));
printf("Randomly generated array: ");
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100; 
printf("%d ", arr[i]);
}
printf("\n");
heapSort(arr, n);
printf("Sorted array: ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);}
printf("\n");
free(arr);
return 0;
}