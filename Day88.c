Problem1:Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
This is an optimization problem where binary search on the answer is required.
Input Format
n k
n space-separated integers representing stall positions
Output Format
Print the maximum possible minimum distance between any two cows.
Sample Input
5 3
1 2 8 4 9
Sample Output
3
Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.

Answer:
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int stalls[], int n, int k, int minDist) {
    int count = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }

        if(count >= k)
            return 1;
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    qsort(stalls, n, sizeof(int), compare);

    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}

Problem2:In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.
Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
Constraints:
n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length

Answer:
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int* pos, int n, int m, int minDist) {
    int count = 1;
    int lastPos = pos[0];

    for(int i = 1; i < n; i++) {
        if(pos[i] - lastPos >= minDist) {
            count++;
            lastPos = pos[i];
        }

        if(count >= m)
            return 1;
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlace(position, positionSize, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
