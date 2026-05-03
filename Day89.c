Problem1:Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
Books must be allocated in contiguous order.
Input Format
n m
n space-separated integers representing pages in books
Output Format
Print the minimum possible value of the maximum pages assigned to any student.
Sample Input
4 2
12 34 67 90
Sample Output
113
Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).

Answer:
#include <stdio.h>

int isFeasible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];

            if(students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int low = 0, high = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        if(pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    if(n < m) {
        printf("-1");
        return 0;
    }

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isFeasible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}

Problem2:A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
Constraints:
1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500

Answer:
void findMaxNSum(int* weights, int size, int* low, int* high) {
    for (int i = 0; i < size; i++) {
        if (*low > weights[i]) *low = weights[i];
        *high += weights[i];
    }
}

bool findMinWeights(int* weights, int size, int days, int minWeight) {
    int temp = minWeight;
    int i = 0;
    while (i < size && days > 0) {
        if (temp < weights[i]) {
            days--;
            temp = minWeight;
        } else {
            temp -= weights[i];
            i++;
        }
    }
    return i == size;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0, ans = 0;
    findMaxNSum(weights, weightsSize, &low, &high);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (findMinWeights(weights, weightsSize, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
