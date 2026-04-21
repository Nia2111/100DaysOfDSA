Problem1:Find shortest distances from source vertex in a weighted graph with non-negative weights.
Input Format
n m
u v w
source
Output Format
Distances to all vertices.
Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1
Sample Output
0 2 3 9 6
Explanation
Shortest distances computed via priority queue.

Answer:
#include <stdio.h>
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[105][105];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    int dist[105], visited[105] = {0};
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[source] = 0;

    for(int count = 1; count <= n; count++) {
        int u = -1, minDist = INF;
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INF && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}


Problem2:Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.
Examples:
Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]
Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V

Answer:
void dfs1(int node, int visited[], int graph[105][105], int n, int stack[], int* top) {
    visited[node] = 1;
    for(int i = 0; i < n; i++) {
        if(graph[node][i] && !visited[i])
            dfs1(i, visited, graph, n, stack, top);
    }
    stack[(*top)++] = node;
}

void dfs2(int node, int visited[], int rev[105][105], int n) {
    visited[node] = 1;
    for(int i = 0; i < n; i++) {
        if(rev[node][i] && !visited[i])
            dfs2(i, visited, rev, n);
    }
}
