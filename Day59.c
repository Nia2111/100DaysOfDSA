Problem1:Construct a binary tree from given inorder and postorder traversal arrays.
Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal
Output Format:
- Print preorder traversal of constructed tree
Example:
Input:
5
4 2 5 1 3
4 5 2 3 1
Output:
1 2 4 5 3
Explanation:
Postorder gives root at end, inorder divides left and right subtrees.

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    int current = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = newNode(current);

    if (start == end)
        return node;

    int index = findIndex(inorder, start, end, current);

    node->right = buildTree(inorder, postorder, index + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, index - 1, postIndex);

    return node;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}

Problem2:Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

Answer:
#include <stdio.h>
#include <stdlib.h>

#define MAX 6001

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int map[MAX];

struct TreeNode* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    int inIndex = map[rootVal + 3000];

    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    for (int i = 0; i < n; i++) {
        map[inorder[i] + 3000] = i;
    }

    int postIndex = n - 1;
    return build(inorder, postorder, 0, n - 1, &postIndex);
}

void printPreorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int inorder[] = {9,3,15,20,7};
    int postorder[] = {9,15,7,20,3};
    int n = 5;

    struct TreeNode* root = buildTree(inorder, postorder, n);

    printPreorder(root);

    return 0;
}
