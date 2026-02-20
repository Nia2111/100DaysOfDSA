Problem1: Given an array of integers, count the number of subarrays whose sum is equal to zero.
Input:
- First line: integer n
- Second line: n integers
Output:
- Print the count of subarrays having sum zero
Example:
Input:
6
1 -1 2 -2 3 -3
Output:
6
Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

Anwser:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int offset = MAX;
    int size = 2 * MAX + 1;
    int *freq = (int *)calloc(size, sizeof(int));

    int prefix_sum = 0;
    int count = 0;

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    printf("%d\n", count);

    free(freq);
    return 0;
}

Problem2:Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105

Answer:
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void threeSum(int nums[], int n) {
    qsort(nums, n, sizeof(int), compare);

    int found = 0;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                found = 1;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    if (!found) {
        printf("[]\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    threeSum(nums, n);
    return 0;
}
