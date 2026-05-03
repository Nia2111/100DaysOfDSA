Problem1:Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
Determine the minimum time required to paint all boards.
Input Format
n k
n space-separated integers representing board lengths
Output Format
Print the minimum time required to paint all boards.
Sample Input
4 2
10 20 30 40
Sample Output
60
Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.

Answer:
#include <stdio.h>

int isFeasible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];

            if(painters > k)
                return 0;
        } else {
            currentSum += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int low = 0, high = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if(boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isFeasible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}

Problem2:Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

Answer:
int canSplit(int* nums, int n, int k, int maxSum) {
    int parts = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + nums[i] > maxSum) {
            parts++;
            currentSum = nums[i];

            if(parts > k)
                return 0;
        } else {
            currentSum += nums[i];
        }
    }

    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int low = 0, high = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
