Problem1:Perform BFS from a given source using queue.
Input:
- n
- adjacency list
- source s
Output:
- BFS traversal order

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int item = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return item;
}

int isEmpty() {
    return front == -1;
}

void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, adj[MAX][MAX], s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(n, adj, s);

    return 0;
}

Problem2:You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

Answer:
#include <stdio.h>

#define MAX 10

typedef struct {
    int x, y;
} Node;

Node queue[MAX * MAX];
int front = 0, rear = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int isValid(int x, int y, int m, int n) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    int minutes = -1;

    while (front < rear) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];

                if (isValid(nx, ny, m, n) && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;   
                    fresh--;
                    queue[rear++] = (Node){nx, ny};
                }
            }
        }
    }

    if (fresh > 0) return -1;

    return minutes;
}

int main() {
    int m, n;
    int grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter grid:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);
    printf("Minimum minutes: %d\n", result);

    return 0;
}
