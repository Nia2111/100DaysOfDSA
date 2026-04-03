Problem1:Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.
Input:
- n (vertices)
- m (edges)
- m pairs (u, v)
Output:
- n x n adjacency matrix

Answer:
#include <stdio.h>

int main() {
    int n, m;
  
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    int adj[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    int u, v;

    int directed;
    printf("Enter 1 for directed graph, 0 for undirected graph: ");
    scanf("%d", &directed);
   
    printf("Enter %d edges (u v):\n", m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1;
        
        if(!directed) {
            adj[v][u] = 1;
        }
    }
  
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

Problem2:There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

Answer:
#include <stdio.h>

#define MAX 200

int isConnected[MAX][MAX];
int visited[MAX];
int n;

void dfs(int city) {
    visited[city] = 1;
    
    for(int i = 0; i < n; i++) {
        if(isConnected[city][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int findProvinces() {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }
    
    return count;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
 
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    int provinces = findProvinces();
    
    printf("Number of provinces: %d\n", provinces);
    
    return 0;
}
