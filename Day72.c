Problem1:Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
Input Format
A single string s.
Output Format
Print the first repeated character. If no character is repeated, print -1.
Sample Input
geeksforgeeks
Sample Output
e

Answer:
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int seen[26] = {0};  

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        seen[index] = 1;
    }

    printf("-1\n");
    return 0;
}

Problem2:Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.
Examples:
Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104

Answer:
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    memset(dp, -1, sizeof(dp));

    int result = tsp(1, 0);

    printf("%d\n", result);

    return 0;
}
