Problem1:Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.

Answer:
#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* bucketSizes = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx][bucketSizes[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}

Problem2:Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109.

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    int gap = (maxVal - minVal + numsSize - 2) / (numsSize - 1);
    int bucketCount = numsSize - 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == minVal || nums[i] == maxVal) continue;
        int idx = (nums[i] - minVal) / gap;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0;
    int prev = minVal;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;
        if (bucketMin[i] - prev > maxGap) maxGap = bucketMin[i] - prev;
        prev = bucketMax[i];
    }

    if (maxVal - prev > maxGap) maxGap = maxVal - prev;

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}
