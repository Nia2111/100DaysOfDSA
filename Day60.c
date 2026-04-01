Problem1:Check whether a given binary tree satisfies the Min-Heap property.
Input Format:
- First line contains integer N
- Second line contains level-order traversal
Output Format:
- Print YES if valid Min-Heap, otherwise NO
Example:
Input:
7
1 3 5 7 9 8 10
Output:
YES
Explanation:
Each parent node must be smaller than its children.

Answer:
#include <stdio.h>

int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            return 0;

        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

Problem2:You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0

Answer:
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int cameras = 0;

int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; 

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1; // Has camera
    }

    if (left == 1 || right == 1) {
        return 2; 
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0) {
        cameras++;
    }
    return cameras;
}

int main() {
    /*
        Example 1:
              0
             /
            0
           / \
          0   0
    */

    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    printf("%d\n", minCameraCover(root));

    return 0;
}
