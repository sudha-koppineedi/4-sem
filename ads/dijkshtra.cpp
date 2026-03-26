#include<stdio.h>

#define infinity 999

void dijkstra(int n, int v, int cost[10][10], int dist[]) {
    int i, u, count, w, flag[10], min;

    // Initialize distances and visited array
    for(i = 0; i < n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    dist[v] = 0;
    flag[v] = 1;
    count = 1;

    // Main loop
    while(count < n) {
        min = infinity;
        u = -1;

        // Find minimum distance unvisited node
        for(w = 0; w < n; w++) {
            if(!flag[w] && dist[w] < min) {
                min = dist[w];
                u = w;
            }
        }

        if(u == -1)
            break;

        flag[u] = 1;
        count++;

        // Update distances of adjacent nodes
        for(w = 0; w < n; w++) {
            if(!flag[w] && (dist[u] + cost[u][w] < dist[w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j;
    int cost[10][10], dist[10];

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter cost matrix (0 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = infinity;
        }
    }

    printf("Enter source node (0 to %d):\n", n-1);
    scanf("%d", &v);

    if(v < 0 || v >= n) {
        printf("Invalid source node\n");
        return 1;
    }

    dijkstra(n, v, cost, dist);

    printf("Shortest paths from node %d:\n", v);
    for(i = 0; i < n; i++) {
        if(i != v) {
            printf("%d -> %d = %d\n", v, i, dist[i]);
        }
    }

    return 0;
}




