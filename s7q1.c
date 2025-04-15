#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source);

int main() {
    int n, i, j;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use a large number for INF, e.g., 9999 for no path):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                graph[i][j] = INF;  
            }
        }
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source) {
    int dist[MAX_VERTICES], visited[MAX_VERTICES], i, j;

    for (i = 0; i < n; i++) {
        dist[i] = INF;      
        visited[i] = 0;    
    }
    dist[source] = 0;  

     for (i = 0; i < n - 1; i++) {

        int min = INF, u;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min) {
                min = dist[j];
                u = j;
            }
        }

        
        visited[u] = 1;

        
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != INF && dist[u] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Shortest distances from source vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d: INF\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}
