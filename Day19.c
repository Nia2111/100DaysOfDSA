Problem1:Given an array of integers, find two elements whose sum is closest to zero.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the pair of elements whose sum is closest to zero
Example:
Input:
5
1 60 -10 70 -80
Output:
-10 1
Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
Answer:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = INT_MAX;
    int num1 = arr[left], num2 = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", num1, num2);

    return 0;
}

Problem2:Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
Constraints:
n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

Answer:
#include <stdio.h>
#include <limits.h>

int maxCircularSubarraySum(int nums[], int n) {
    int total = 0;

    int max_sum = INT_MIN, curr_max = 0;
    int min_sum = INT_MAX, curr_min = 0;

    for (int i = 0; i < n; i++) {
        int x = nums[i];

        curr_max = (curr_max + x > x) ? curr_max + x : x;
        max_sum = (curr_max > max_sum) ? curr_max : max_sum;

        curr_min = (curr_min + x < x) ? curr_min + x : x;
        min_sum = (curr_min < min_sum) ? curr_min : min_sum;

        total += x;
    }

    if (max_sum < 0)
        return max_sum;

    int circular_sum = total - min_sum;
    return (max_sum > circular_sum) ? max_sum : circular_sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxCircularSubarraySum(nums, n);
    printf("%d\n", result);

    return 0;
}
