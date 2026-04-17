Problem1:Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
Input Format
An integer array arr[].
Output Format
Print the length of the longest subarray with sum equal to zero.
Sample Input
15 -2 2 -8 1 7 10 23
Sample Output
5
Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

Answer:
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[2000], index[2000], size = 0;
    int sum = 0, maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            maxLen = i + 1;

        int found = 0;
        for(int j = 0; j < size; j++) {
            if(prefix[j] == sum) {
                int len = i - index[j];
                if(len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        if(!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d", maxLen);
    return 0;
}


Problem2:There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
Return true if and only if it is bipartite.
Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
Constraints:
graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.

Answer:
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[105];
    for(int i = 0; i < graphSize; i++)
        color[i] = -1;

    int queue[1000];

    for(int i = 0; i < graphSize; i++) {
        if(color[i] != -1)
            continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while(front < rear) {
            int node = queue[front++];

            for(int j = 0; j < graphColSize[node]; j++) {
                int next = graph[node][j];

                if(color[next] == -1) {
                    color[next] = 1 - color[node];
                    queue[rear++] = next;
                }
                else if(color[next] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}
