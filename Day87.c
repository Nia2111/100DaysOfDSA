Problem1:Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
Input:
- First line: an integer n
Output:
- Print the integer square root of n
Examples:
Input:
64
Output:
8
Input:
20
Output:
4
Input:
1
Output:
1
Explanation:
Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n. If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.

Answer:
#include <stdio.h>

int mySqrt(int n) {
    if(n == 0) return 0;

    int low = 1, high = n;
    int ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid == n)
            return (int)mid;
        else if(mid * mid < n) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", mySqrt(n));

    return 0;
}

Problem2:Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. 
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
Constraints:
0 <= x <= 231 - 1

Answer:
int mySqrt(int x) {
    if(x == 0) return 0;

    int low = 1, high = x;
    int ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid <= (long long)x) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}
