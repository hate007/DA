#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int vertex, int* visited, struct Node** stack) {
    visited[vertex] = 1;
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;
    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited, stack);
        }
        temp = temp->next;
    }
    *stack = createNode(vertex);
    (*stack)->next = adjList;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    struct Node* stack = NULL;
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, &stack);
        }
    }
    printf("Topological Sorting: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    topologicalSort(graph);
    return 0;
}
