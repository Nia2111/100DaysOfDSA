Problem: Given an array of integers, rotate the array to the right by k positions.
Input:
- First line: integer n
- Second line: n integers
- Third line: integer k
Output:
- Print the rotated array
Example:
Input:
5
1 2 3 4 5
2
Output:
4 5 1 2 3

Answer:
#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;

    reverse(arr, 0, n - 1);

    reverse(arr, 0, k - 1);

    reverse(arr, k, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

Problem2:Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

Answer:
#include <stdio.h>

void productExceptSelf(int nums[], int n, int result[]) {
    result[0] = 1;
    for(int i = 1; i < n; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * suffix;
        suffix *= nums[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n], result[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, n, result);

    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
