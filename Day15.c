Problem1: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
Input:
- First line: two integers m and n
- Next m lines: n integers each
Output:
- Print the sum of the primary diagonal elements
Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output:
15
Explanation:
1 + 5 + 9 = 15

Answer:
#include <stdio.h>

int main() {
    int m, n;
    int sum = 0;

    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);

    return 0;
}

Problem2:Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Answer:
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int firstRowZero = 0, firstColZero = 0;

    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero) {
        for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if(firstColZero) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
