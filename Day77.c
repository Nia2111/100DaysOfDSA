Problem1:Using BFS or DFS, check if the entire graph is connected.
Input Format
n m
edges
Output Format
CONNECTED
NOT CONNECTED
Sample Input
4 2
1 2
3 4
Sample Output
NOT CONNECTED

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}

Problem2:There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.
Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
Constraints:
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];

int disc[MAX], low[MAX], visited[MAX];
int timeCounter;

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->v = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    Node* temp = adj[u];

    while (temp != NULL) {
        int v = temp->v;

        if (v == parent) {
            temp = temp->next;
            continue;
        }

        if (!visited[v]) {
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u]) {
                printf("[%d, %d]\n", u, v);
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    return 0;
}
