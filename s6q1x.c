#include <stdio.h>

#define MAX 100
#define INF 9999

int main() {
    int cost[MAX][MAX], visited[MAX], min, n, i, j, edges = 0;
    int x, y;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, cost[x][y]);
        visited[y] = 1;
        edges++;
    }

    return 0;
}
