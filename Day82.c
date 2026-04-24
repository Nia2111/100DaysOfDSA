Problem1:Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.
Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)
Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x
Example:
Input:
7
1 2 4 4 4 5 7
4
Output:
2 5
Explanation:
For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
- The lower bound is at index 2, which is the first occurrence of 4.
- The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
Binary Search is used to find both bounds efficiently in O(log n) time.

Answer:
#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    printf("%d %d", lowerBound(arr, n, x), upperBound(arr, n, x));

    return 0;
}


Problem2:Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

Answer:
int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int ans = numsSize;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
