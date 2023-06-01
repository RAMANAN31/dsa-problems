#include <stdio.h>
#include <stdbool.h>

void BFS(int graph[][n], int n, int start) {
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int queue[n];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front != rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}
