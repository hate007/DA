#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 100

struct Node {
    int value;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node* adjacencyList[MAX_NODES];
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void DFS(struct Graph* graph, int node, int visited[], int stack[], int* top) {
    visited[node] = 1;
    struct Node* current = graph->adjacencyList[node];
    while (current != NULL) {
        int neighbor = current->value;
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited, stack, top);
        }
        current = current->next;
    }
    stack[++(*top)] = node;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int top = -1;
    for (int i = 0; i < graph->numNodes; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &top);
        }
    }
    printf("Topological Sorting: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = 6;
    for (int i = 0; i < graph->numNodes; ++i) {
        graph->adjacencyList[i] = NULL;
    }
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    topologicalSort(graph);
    return 0;
}
