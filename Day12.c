Problem1: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix
Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"
Example:
Input:
3 3
1 2 3
2 4 5
3 5 6
Output:
Symmetric Matrix
Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].
Test Cases:
Test Case 1:
Input:
2 2
1 2
2 1
Output:
Symmetric Matrix
Test Case 2:
Input:
3 3
1 0 1
2 3 4
1 4 5
Output:
Not a Symmetric Matrix
Test Case 3:
Input:
2 3
1 2 3
4 5 6
Output:
Not a Symmetric Matrix

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
    
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    
    int symmetric = 1;  
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }
    
    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");
    
    return 0;
}


Problem2:Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Example 1:
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
Follow up:
What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?

Answer:
#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool isToeplitz = true;

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != matrix[i-1][j-1]) {
                isToeplitz = false;
                break;
            }
        }
        if(!isToeplitz)
            break;
    }

    if(isToeplitz)
        printf("true");
    else
        printf("false");

    return 0;
}




