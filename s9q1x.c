#include <stdio.h>

#define MAX 10

int optimalBST(int keys[], int freq[], int n) {
    int cost[MAX][MAX];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = 999999;

            int sum = 0;
            for (int s = i; s <= j; s++)
                sum += freq[s];

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) + sum;

                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys) / sizeof(keys[0]);

    int minCost = optimalBST(keys, freq, n);
    printf("Minimum cost of Optimal BST (best-case complexity): %d\n", minCost);

    return 0;
}
