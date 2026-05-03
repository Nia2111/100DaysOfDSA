Problem1:Implement Quick Sort using partition method (Lomuto or Hoare).

Answer:
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

Problem2:Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104.

Answer:
#include <stdio.h>

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int* nums, int low, int high) {
    int pivot = nums[low];
    int j = low;

    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            j++;
            swap(nums, i, j);
        }
    }
    swap(nums, low, j);
    return j;
}

int QSelect(int* nums, int low, int high, int k) {
    if (low <= high) {
        int p = partition(nums, low, high);

        if (p == k) return nums[p];
        if (p < k) return QSelect(nums, p + 1, high, k);
        else return QSelect(nums, low, p - 1, k);
    }
    return nums[low];
}

int findKthLargest(int* nums, int numsSize, int k) {
    return QSelect(nums, 0, numsSize - 1, numsSize - k);
}
