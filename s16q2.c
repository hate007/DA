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

int DFS(struct Graph* graph, int startVertex, int currentVertex, int numVisited, int start) {
    graph->visited[currentVertex] = 1;
    if (numVisited == graph->numVertices && start == startVertex) {
        return 1;
    }
    struct Node* temp = graph->adjLists[currentVertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex]) {
            if (DFS(graph, startVertex, adjVertex, numVisited + 1, start)) {
                return 1;
            }
        }
        temp = temp->next;
    }
    graph->visited[currentVertex] = 0;
    return 0;
}

int isHamiltonianCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (DFS(graph, i, i, 1, i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    if (isHamiltonianCycle(graph)) {
        printf("The graph contains a Hamiltonian cycle.\n");
    } else {
        printf("The graph does not contain a Hamiltonian cycle.\n");
    }
    return 0;
}
