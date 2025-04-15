#include <stdio.h>
#include <stdlib.h>
// Structure to represent an edge in the graph
struct Edge {
int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
int parent;
int rank;
};
// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int myComp(const void* a, const void* b);
void KruskalMST(struct Edge* edges, int V, int E);
// Function to find the subset of an element iint find(struct Subset subsets[], int i) {
if (subsets[i].parent != i)
subsets[i].parent = find(subsets, subsets[i].parent);
return subsets[i].parent;
}
// Function that performs union of two subsets
void Union(struct Subset subsets[], int x, int y) {
int xroot = find(subsets, x);
int yroot = find(subsets, y);
if (subsets[xroot].rank < subsets[yroot].rank)
subsets[xroot].parent = yroot;
else if (subsets[xroot].rank > subsets[yroot].rank)
subsets[yroot].parent = xroot;
else {
subsets[yroot].parent = xroot;
subsets[xroot].rank++;
}
}
// Comparator function used by qsort() to sort edges based on weight
int myComp(const void* a, const void* b) {
struct Edge* a1 = (struct Edge*)a;
struct Edge* b1 = (struct Edge*)b;
return a1->weight > b1->weight;
}
// Function to construct MST using Kruskal's algorithm
void KruskalMST(struct Edge* edges, int V, int E) {
struct Edge result[V]; // To store the resultant MSTint e = 0; // Index used to pick the next edge
qsort(edges, E, sizeof(edges[0]), myComp);
struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
for (int v = 0; v < V; v++) {
subsets[v].parent = v;
subsets[v].rank = 0;
}
while (e < V - 1 && E > 0) {
struct Edge next_edge = edges[E - 1];
E--;
int x = find(subsets, next_edge.src);
int y = find(subsets, next_edge.dest);
if (x != y) {
result[e++] = next_edge;
Union(subsets, x, y);
}
}
printf("Edges of constructed MST:\n");
for (int i = 0; i < e; i++)
printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
free(subsets);
}
int main() {
int V = 4; // Number of vertices in graph
int E = 5; // Number of edges in graph
struct Edge edges[] = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };
KruskalMST(edges, V, E);
return 0;}