Problem1:Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
Input Format
n m
u v w
...
Output Format
Total weight of MST.
Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2
Sample Output
6
Explanation
One possible MST edges: (2-3), (3-4), (1-2)

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

    int selected[105] = {0};
    selected[1] = 1;
    int edges = 0, total = 0;

    while(edges < n - 1) {
        int min = INF, x = 0, y = 0;

        for(int i = 1; i <= n; i++) {
            if(selected[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        total += graph[x][y];
        edges++;
    }

    printf("%d", total);
    return 0;
}


Problem2:Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
Example 1:
Input:
Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-
Removing the vertex 4 will disconnect the
graph as-
Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
Constraints:
1 ≤ V ≤ 105

Answer:
int timer;

void dfsAP(int node, int parent, int visited[], int disc[], int low[], int mark[], int adj[105][105], int n) {
    visited[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(int v = 0; v < n; v++) {
        if(adj[node][v] == 0)
            continue;

        if(v == parent)
            continue;

        if(!visited[v]) {
            dfsAP(v, node, visited, disc, low, mark, adj, n);
            if(low[v] < low[node])
                low[node] = low[v];

            if(low[v] >= disc[node] && parent != -1)
                mark[node] = 1;

            child++;
        }
        else {
            if(disc[v] < low[node])
                low[node] = disc[v];
        }
    }

    if(parent == -1 && child > 1)
        mark[node] = 1;
}
