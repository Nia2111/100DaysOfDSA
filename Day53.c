Problem1:Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)
Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
Example:
Input:
7
1 2 3 4 5 6 7
Output:
4
2
1 5 6
3
7
Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if(root == NULL) return;

    struct Pair q[1000];
    int front = 0, rear = 0;

    int hdArr[1000];
    int valArr[1000];
    int count = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while(front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node;
        int hd = cur.hd;

        hdArr[count] = hd;
        valArr[count] = temp->data;
        count++;

        if(temp->left != NULL) {
            q[rear].node = temp->left;
            q[rear].hd = hd - 1;
            rear++;
        }

        if(temp->right != NULL) {
            q[rear].node = temp->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }

    for(int i = -100; i <= 100; i++) {
        int printed = 0;
        for(int j = 0; j < count; j++) {
            if(hdArr[j] == i) {
                printf("%d ", valArr[j]);
                printed = 1;
            }
        }
        if(printed)
            printf("\n");
    }
}


Problem2:Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

Answer:
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** ans = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

    struct TreeNode* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;
        ans[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];
            ans[*returnSize][i] = node->val;

            if(node->left) q[rear++] = node->left;
            if(node->right) q[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return ans;
}
