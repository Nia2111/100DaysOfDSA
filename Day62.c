Problem1:Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
Input:
- n (vertices)
- m (edges)
- edges (u, v)
Output:
- List of adjacency lists for each vertex

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("\nAdjacency List:\n");
    printGraph(graph);

    return 0;
}

Problem2:There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
Example 1:
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
Constraints:
n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int visited[MAX];

void dfs(int room, int** rooms, int* roomsColSize) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize);
        }
    }
}

int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = 0;
    }

    dfs(0, rooms, roomsColSize);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return 0; // false
        }
    }

    return 1;
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    printf("Enter number of keys in each room:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &roomsColSize[i]);
        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));
    }

    printf("Enter keys for each room:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(rooms, n, roomsColSize)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
