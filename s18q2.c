#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 10

void DFS(int graph[MAX_NODES][MAX_NODES], int node, bool visited[MAX_NODES]) {
    visited[node] = true;
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

void analyzeGraph(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    bool visited[MAX_NODES] = {false};
    int liveNodes = 0, eNodes = 0, deadNodes = 0;
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            liveNodes++;
        }
    }
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
        int outgoingEdges = 0;
        for (int j = 0; j < numNodes; j++) {
            if (graph[i][j]) {
                outgoingEdges++;
            }
        }
        if (outgoingEdges == 0) {
            eNodes++;
        }
    }
    deadNodes = numNodes - liveNodes;
    printf("Live Nodes: %d\n", liveNodes);
    printf("E Nodes: %d\n", eNodes);
    printf("Dead Nodes: %d\n", deadNodes);
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int numNodes = 5;
    analyzeGraph(graph, numNodes);
    return 0;
}
