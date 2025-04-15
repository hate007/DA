#include <stdio.h>

#define V 5
#define INF 99999  // A large number used as "infinity"

int minKey(int key[], int mst[]) {
    int min = INF, min_index;
    for (int i = 0; i < V; i++) {
        if (mst[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim(int g[V][V]) {
    int parent[V], key[V], mst[V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, mst);
        mst[u] = 1;

        for (int v = 0; v < V; v++) {
            if (g[u][v] && mst[v] == 0 && g[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, g[i][parent[i]]);
    }
}

int main() {
    int g[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(g);
    return 0;
}
