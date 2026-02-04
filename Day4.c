Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the reversed array, space-separated
Example:
Input:
5
1 2 3 4 5
Output:
5 4 3 2 1
Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays

Answer:
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = n - 1;

    while(left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

Problem2:Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:
The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.
int k = removeElement(nums, val); // Calls your implementation
assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

Amswer:
#include <stdio.h>

int removeElement(int nums[], int numsSize, int val) {
    int i = 0;
    int n = numsSize;

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];  
            n--;                   
        } else {
            i++;                   
        }
    }

    return n; 
}

int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int size = sizeof(nums) / sizeof(nums[0]);

    int k = removeElement(nums, size, val);

    printf("k = %d\n", k);
    printf("Modified array: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
