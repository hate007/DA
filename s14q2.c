#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (struct Node* temp = graph->adjLists[vertex]; temp; temp = temp->next) {
        if (!visited[temp->data]) {
            DFS(graph, temp->data, visited);
        }
    }
}

void BFS(struct Graph* graph, int startVertex) {
    int visited[graph->numVertices];
    int queue[graph->numVertices], front = 0, rear = 0;
    for (int i = 0; i < graph->numVertices; i++) visited[i] = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (struct Node* temp = graph->adjLists[currentVertex]; temp; temp = temp->next) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
        }
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        for (struct Node* temp = graph->adjLists[i]; temp; temp = temp->next) {
            printf("%d -> ", temp->data);
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printf("Graph:\n");
    printGraph(graph);
    printf("\nDFS traversal starting from vertex 0: ");
    int visitedDFS[4] = {0};
    DFS(graph, 0, visitedDFS);
    printf("\nBFS traversal starting from vertex 0: ");
    BFS(graph, 0);
    return 0;
}
