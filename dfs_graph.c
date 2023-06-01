#include <stdio.h>
#include <stdbool.h>

void DFS(int graph[][n], int n, int start) {
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int stack[n];
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            visited[v] = true;
            printf("%d ", v);

            for (int i = n - 1; i >= 0; i--) {
                if (graph[v][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
