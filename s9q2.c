#include <stdio.h>
#define MAX 10
int subset[MAX];
int n, sum;

void displaySubset() {
    printf("Subset: { ");
    for (int i = 0; i < n; i++) {
        if (subset[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("}\n");
}

void generateSubset(int k, int currentSum, int remainingSum) {
    subset[k] = 1;
    if (currentSum + k + 1 == sum) {
        displaySubset();
    } else if (currentSum + k + 1 < sum) {
        generateSubset(k + 1, currentSum + k + 1, remainingSum - (k + 1));
    }
    subset[k] = 0;
    if (currentSum + remainingSum - k >= sum) {
        generateSubset(k + 1, currentSum, remainingSum - k);
    }
}

void subsetSum() {
    int totalSum = (n * (n + 1)) / 2;
    if (totalSum % 2 != 0) {
        printf("No subset with given sum exists.\n");
        return;
    }
    sum = totalSum / 2;
    printf("Subsets with sum %d are:\n", sum);
    generateSubset(0, 0, totalSum);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid input for the number of elements.\n");
        return 1;
    }
    subsetSum();
    return 0;
}
