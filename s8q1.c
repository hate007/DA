#include <stdio.h>
struct Item {
int value;
int weight;
float ratio;
};
void swap(struct Item *a, struct Item *b) {
struct Item temp = *a;
*a = *b;*b = temp;
}
void sortItems(struct Item items[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (items[j].ratio < items[j + 1].ratio) {
swap(&items[j], &items[j + 1]);
}
}
}
}
float knapsack(int capacity, struct Item items[], int n) {
sortItems(items, n);
float totalValue = 0.0;
int remainingCapacity = capacity;
for (int i = 0; i < n; i++) {
if (items[i].weight <= remainingCapacity) {
totalValue += items[i].value;
remainingCapacity -= items[i].weight;
} else {
totalValue += (float)items[i].value * remainingCapacity / items[i].weight;
break;
}
}
return totalValue;
}
int main() {
int n, capacity;printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[n];
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
printf("Enter the value and weight of each item:\n");
for (int i = 0; i < n; i++) {
printf("Item %d:\n", i + 1);
printf("Value: ");
scanf("%d", &items[i].value);
printf("Weight: ");
scanf("%d", &items[i].weight);
items[i].ratio = (float)items[i].value / items[i].weight;
}
float maxValue = knapsack(capacity, items, n);
printf("Maximum value in the knapsack: %.2f\n", maxValue);
return 0;
}