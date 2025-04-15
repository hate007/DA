#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

void knapsackLCBB(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compare);
    int curWeight = 0;
    double curValue = 0.0;
    int finalSet[n];
    for (int i = 0; i < n; i++)
        finalSet[i] = 0;
    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= capacity) {
            finalSet[i] = 1;
            curWeight += items[i].weight;
            curValue += items[i].value;
        } else {
            double remainingWeight = capacity - curWeight;
            curValue += (remainingWeight / items[i].weight) * items[i].value;
            break;
        }
    }
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (finalSet[i]) {
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, items[i].weight, items[i].value);
        }
    }
    printf("Total value: %.2f\n", curValue);
}

int main() {
    int capacity, n;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    knapsackLCBB(capacity, items, n);
    return 0;
}
