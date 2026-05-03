Problem1:For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).

Answer:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    Pair temp[right - left + 1];
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}


Problem2:Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:
Input: nums = [-1]
Output: [0]
Example 3:
Input: nums = [-1,-1]
Output: [0,0]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104.

Answer:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int counts[]) {
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    Pair *temp = (Pair *)malloc((right - left + 1) * sizeof(Pair));

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int counts[]) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);
    merge(arr, left, mid, right, counts);
}

int* countSmaller(int nums[], int n) {
    Pair *arr = (Pair *)malloc(n * sizeof(Pair));
    int *counts = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, counts);

    free(arr);
    return counts;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int *result = countSmaller(nums, n);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
