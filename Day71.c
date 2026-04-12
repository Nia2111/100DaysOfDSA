Problem1:Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m
Input Format
Same as previous.
Output Format
Result of SEARCH operations.
Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15
Sample Output
FOUND
NOT FOUND
Explanation
Collisions resolved using i² jumps.

Answer:
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY)
            return 0; 

        if (table[index] == key)
            return 1;  

        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);  
    scanf("%d", &q);  

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char operation[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}


Problem2:You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int minCostConnectPoints(int** points, int n) {
    int* minDist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;  
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u][0], points[u][1],
                                     points[v][0], points[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}

int main() {
    int n;
    scanf("%d", &n);

    int** points = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}
