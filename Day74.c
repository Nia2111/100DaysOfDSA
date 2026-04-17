Problem1:Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.
Output Format
Print the name of the winning candidate followed by the number of votes received.
Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
Sample Output
john 4
Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

Answer:
#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate arr[1000];
    int size = 0;

    for(int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        int found = 0;
        for(int j = 0; j < size; j++) {
            if(strcmp(arr[j].name, temp) == 0) {
                arr[j].count++;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(arr[size].name, temp);
            arr[size].count = 1;
            size++;
        }
    }

    char winner[100];
    int maxVotes = -1;

    for(int i = 0; i < size; i++) {
        if(arr[i].count > maxVotes) {
            maxVotes = arr[i].count;
            strcpy(winner, arr[i].name);
        }
        else if(arr[i].count == maxVotes) {
            if(strcmp(arr[i].name, winner) < 0) {
                strcpy(winner, arr[i].name);
            }
        }
    }

    printf("%s %d", winner, maxVotes);
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
struct Node {
    int vertex;
    struct Node* next;
};

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    struct Node* temp = adj[node];

    while(temp != NULL) {
        if(!visited[temp->vertex])
            dfs(temp->vertex, adj, visited);
        temp = temp->next;
    }
}

int countComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    struct Node* adj[2005] = {NULL};
    int visited[2005] = {0};

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}
