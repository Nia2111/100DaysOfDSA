Problem1:Detect cycle in directed graph using DFS and recursion stack.
Output:
- YES if cycle exists

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0; 
    return 0;
}

int hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v); // directed edge
    }

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

Problem2:There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 2005

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int b, int a) {
    Node* newNode = createNode(a);
    newNode->next = adj[b];
    adj[b] = newNode;
}

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0; 
    return 0;
}

int canFinish(int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 0; 
        }
    }
    return 1; 
}

int main() {
    int numCourses, m;
    scanf("%d %d", &numCourses, &m);

    for (int i = 0; i < numCourses; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        addEdge(b, a); 
    }

    if (canFinish(numCourses))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
