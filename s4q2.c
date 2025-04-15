#include <stdio.h>
#define MAX_ITEMS 100
// Structure to represent an item
struct Item {int value;
int weight;
};
// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
double ratio_a = ((double)(((struct Item *)a)->value)) / (((struct Item *)a)->weight);
double ratio_b = ((double)(((struct Item *)b)->value)) / (((struct Item *)b)->weight);
return ratio_b - ratio_a;
}
// Function to solve the knapsack problem using a greedy method
void knapsackGreedy(int capacity, struct Item items[], int n) {
// Sort items based on value-to-weight ratio
qsort(items, n, sizeof(struct Item), compare);
int currentWeight = 0; // Current weight in the knapsack
double totalValue = 0.0; // Total value of items selected
printf("Selected items:\n");
for (int i = 0; i < n; i++) {
// If adding the current item doesn't exceed the capacity
if (currentWeight + items[i].weight <= capacity) {
// Select the current item
printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
currentWeight += items[i].weight;
totalValue += items[i].value;} else {
// Take a fraction of the current item to fill the knapsack
int remainingCapacity = capacity - currentWeight;
totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
printf("Item %d - Value: %d, Weight: %d (Fraction: %.2lf)\n", i + 1, items[i].value, items[i].weight,
((double)remainingCapacity / items[i].weight));
break;
}
}
printf("Total Value: %.2lf\n", totalValue);
}
int main() {
int capacity, n;
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[MAX_ITEMS];
printf("Enter the value and weight of each item:\n");
for (int i = 0; i < n; i++) {
printf("Item %d: ", i + 1);scanf("%d %d", &items[i].value, &items[i].weight);
}
knapsackGreedy(capacity, items, n);
return 0;
}#include <stdio.h>
#define MAX_ITEMS 100
// Structure to represent an item
struct Item {int value;
int weight;
};
// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
double ratio_a = ((double)(((struct Item *)a)->value)) / (((struct Item *)a)->weight);
double ratio_b = ((double)(((struct Item *)b)->value)) / (((struct Item *)b)->weight);
return ratio_b - ratio_a;
}
// Function to solve the knapsack problem using a greedy method
void knapsackGreedy(int capacity, struct Item items[], int n) {
// Sort items based on value-to-weight ratio
qsort(items, n, sizeof(struct Item), compare);
int currentWeight = 0; // Current weight in the knapsack
double totalValue = 0.0; // Total value of items selected
printf("Selected items:\n");
for (int i = 0; i < n; i++) {
// If adding the current item doesn't exceed the capacity
if (currentWeight + items[i].weight <= capacity) {
// Select the current item
printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
currentWeight += items[i].weight;
totalValue += items[i].value;} else {
// Take a fraction of the current item to fill the knapsack
int remainingCapacity = capacity - currentWeight;
totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
printf("Item %d - Value: %d, Weight: %d (Fraction: %.2lf)\n", i + 1, items[i].value, items[i].weight,
((double)remainingCapacity / items[i].weight));
break;
}
}
printf("Total Value: %.2lf\n", totalValue);
}
int main() {
int capacity, n;
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[MAX_ITEMS];
printf("Enter the value and weight of each item:\n");
for (int i = 0; i < n; i++) {
printf("Item %d: ", i + 1);scanf("%d %d", &items[i].value, &items[i].weight);
}
knapsackGreedy(capacity, items, n);
return 0;
}#include <stdio.h>
#define MAX_ITEMS 100
// Structure to represent an item
struct Item {int value;
int weight;
};
// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
double ratio_a = ((double)(((struct Item *)a)->value)) / (((struct Item *)a)->weight);
double ratio_b = ((double)(((struct Item *)b)->value)) / (((struct Item *)b)->weight);
return ratio_b - ratio_a;
}
// Function to solve the knapsack problem using a greedy method
void knapsackGreedy(int capacity, struct Item items[], int n) {
// Sort items based on value-to-weight ratio
qsort(items, n, sizeof(struct Item), compare);
int currentWeight = 0; // Current weight in the knapsack
double totalValue = 0.0; // Total value of items selected
printf("Selected items:\n");
for (int i = 0; i < n; i++) {
// If adding the current item doesn't exceed the capacity
if (currentWeight + items[i].weight <= capacity) {
// Select the current item
printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
currentWeight += items[i].weight;
totalValue += items[i].value;} else {
// Take a fraction of the current item to fill the knapsack
int remainingCapacity = capacity - currentWeight;
totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
printf("Item %d - Value: %d, Weight: %d (Fraction: %.2lf)\n", i + 1, items[i].value, items[i].weight,
((double)remainingCapacity / items[i].weight));
break;
}
}
printf("Total Value: %.2lf\n", totalValue);
}
int main() {
int capacity, n;
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[MAX_ITEMS];
printf("Enter the value and weight of each item:\n");
for (int i = 0; i < n; i++) {
printf("Item %d: ", i + 1);scanf("%d %d", &items[i].value, &items[i].weight);
}
knapsackGreedy(capacity, items, n);
return 0;
}