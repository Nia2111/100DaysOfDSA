Problem1:Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Ordering:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}

Problem2:There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int stack[MAX];
int top = -1;

int n;

void push(int v) {
    stack[++top] = v;
}

bool dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (!dfs(i))
                    return false;
            }
            else if (recStack[i]) {
                return false;
            }
        }
    }

    recStack[v] = 0;
    push(v);
    return true;
}

int* findOrder(int numCourses, int prerequisites[][2], int prereqSize, int* returnSize) {
    n = numCourses;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][a] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!dfs(i)) {
                *returnSize = 0;
                return NULL; // cycle → impossible
            }
        }
    }

    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;

    while (top != -1) {
        result[index++] = stack[top--];
    }

    *returnSize = n;
    return result;
}

int main() {
    int numCourses = 4;
    int prerequisites[][2] = {{1,0},{2,0},{3,1},{3,2}};
    int prereqSize = 4;

    int returnSize;
    int* order = findOrder(numCourses, prerequisites, prereqSize, &returnSize);

    if (returnSize == 0) {
        printf("No valid ordering (cycle detected)\n");
    } else {
        printf("Course Order: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", order[i]);
        }
    }

    return 0;
}
