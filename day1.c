Problem1: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)
Output:
- Print the updated array (n+1 integers) in a single line, space-separated
Example:
Input:
5
1 2 4 5 6
3
3
Output:
1 2 3 4 5 6
Explanation: Insert 3 at position 3, elements [4,5,6] shift right.


Answer:
#include <stdio.h>

int main() {
    int n, pos, x;

    scanf("%d", &n);

    int arr[n + 1];  
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);
 
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



Problem2:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Answer:
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int* ans = twoSum(nums, 4, target, &returnSize);

    printf("[%d, %d]\n", ans[0], ans[1]);

    free(ans);
    return 0;
}
