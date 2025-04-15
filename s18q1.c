
#include <stdio.h>
#include <stdbool.h>
#define V 4
bool isSafe(int graph[][V], int color[], int v, int c) {
for (int i = 0; i < V; i++)
if (graph[v][i] && color[i] == c)
return false;
return true;
}
bool graphColoringUtil(int graph[][V], int color[], int v) {
if (v == V) {
for (int i = 0; i < V; i++)
printf("Vertex %d --> Color %d\n", i, color[i]);
return true;
}for (int c = 1; c <= V; c++) {
if (isSafe(graph, color, v, c)) {
color[v] = c;
if (graphColoringUtil(graph, color, v + 1))
return true;
color[v] = 0;
}
}
return false;
}
bool graphColoring(int graph[][V]) {
int color[V];
for (int i = 0; i < V; i++)
color[i] = 0;
return graphColoringUtil(graph, color, 0);
}
int main() {
int graph[V][V] = { {0, 1, 1, 0},
{1, 0, 1, 0},
{1, 1, 0, 1},{0, 0, 1, 0}
};
if (!graphColoring(graph))
printf("Solution does not exist.\n");
return 0;
}