Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)
Output:
- Print unique elements only, space-separated
Example:
Input:
6
1 1 2 2 3 3
Output:
1 2 3
Explanation: Keep first occurrence of each element: 1, 2, 3

Answer1:
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d ", arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}

Problem2:Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 Follow up: Could you minimize the total number of operations done?

Answer2:
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0; 

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }

    while (k < n) {
        nums[k++] = 0;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
