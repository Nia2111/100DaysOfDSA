Problem1: Read a string and check if it is a palindrome using two-pointer comparison.
Input:
- Single line: string s
Output:
- Print YES if palindrome, otherwise NO
Example:
Input:
level
Output:
YES
Explanation: String reads same forwards and backwards

Answer:
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;
    int isPalindrome = 1;

    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}

Problem2:Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Answer:
#include <stdio.h>

int main() {
    int n1, n2;
    
    scanf("%d", &n1);
    int nums1[n1];
    for(int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];
    for(int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int freq[1001] = {0};

    for(int i = 0; i < n1; i++) {
        freq[nums1[i]]++;
    }

    for(int i = 0; i < n2; i++) {
        if(freq[nums2[i]] > 0) {
            printf("%d ", nums2[i]);
            freq[nums2[i]]--;
        }
    }

    return 0;
}

