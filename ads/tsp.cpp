#include <stdio.h>

#define MAX 10
#define infinity 999

int cost[MAX][MAX];
int visited[MAX];
int n;
int min_cost = infinity;

// TSP function (similar structure)
void tsp(int city, int count, int curr_cost) {
    int i;

    // If all cities visited ? return to start
    if(count == n && cost[city][0] != infinity) {
        int total = curr_cost + cost[city][0];
        if(total < min_cost)
            min_cost = total;
        return;
    }

    // Try all next cities (like relaxation loop)
    for(i = 0; i < n; i++) {
        if(!visited[i] && cost[city][i] != infinity) {
            visited[i] = 1;

            // go deeper (like updating dist)
            tsp(i, count + 1, curr_cost + cost[city][i]);

            // backtrack
            visited[i] = 0;
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of cities:\n");
    scanf("%d", &n);

    printf("Enter cost matrix (0 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = infinity;
        }
    }

    // Initialize visited (like flag[])
    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    tsp(0, 1, 0);

    printf("Minimum travelling cost = %d\n", min_cost);

    return 0;
}
