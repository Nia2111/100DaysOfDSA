Problem1: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)
Output:
- Print a single line containing all arrival times in chronological order, separated by spaces
Example:
Input:
5
10 20 30 50 70
4
15 25 40 60
Output:
10 15 20 25 30 40 50 60 70
Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed

Answer:
#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;

    scanf("%d", &p);
    int log1[p];

    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &q);
    int log2[q];

    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int merged[p + q];

    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    while (i < p) {
        merged[k++] = log1[i++];
    }
  
    while (j < q) {
        merged[k++] = log2[j++];
    }

    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}

Problem2:You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
Follow up: Can you come up with an algorithm that runs in O(m + n) time?

Answer2:
#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;          
    int j = n - 1;          
    int k = m + n - 1;      

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
