#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

void nearestNeighbor(int dist[MAX_CITIES][MAX_CITIES], int n);

int main() {
    int n, i, j;
    int dist[MAX_CITIES][MAX_CITIES];

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (use 0 for same city and other values for distances):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    nearestNeighbor(dist, n);

    return 0;
}

void nearestNeighbor(int dist[MAX_CITIES][MAX_CITIES], int n) {
    int visited[MAX_CITIES] = {0};
    int totalDistance = 0;
    int currentCity = 0;
    visited[currentCity] = 1;

    printf("The path taken by the salesman: %d ", currentCity);

    for (int i = 1; i < n; i++) {
        int nearestCity = -1;
        int minDistance = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[currentCity][j] < minDistance) {
                minDistance = dist[currentCity][j];
                nearestCity = j;
            }
        }

        visited[nearestCity] = 1;
        totalDistance += minDistance;
        currentCity = nearestCity;
        printf("-> %d ", currentCity);
    }

    totalDistance += dist[currentCity][0];
    printf("-> %d\n", 0);
    printf("Total distance traveled: %d\n", totalDistance);
}
