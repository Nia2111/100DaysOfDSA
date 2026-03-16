Problem1:Perform inorder, preorder, and postorder traversals of a given binary tree.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
Output Format:
- Print inorder, preorder, and postorder traversals
Example:
Input:
7
1 2 3 4 5 6 7
Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1

Answer:
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n, 0);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}

Problem2:Given the root of a binary tree, return the preorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:
Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]
Explanation:
Example 3:
Input: root = []
Output: []
Example 4:
Input: root = [1]
Output: [1]
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
Follow up: Recursive solution is trivial, could you do it iteratively?

Answer:
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Stack {
    struct TreeNode* data[100];
    int top;
};

void push(struct Stack *s, struct TreeNode* node){
    s->data[++s->top] = node;
}

struct TreeNode* pop(struct Stack *s){
    return s->data[s->top--];
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

void preorderTraversal(struct TreeNode* root){
    if(root == NULL)
        return;

    struct Stack s;
    s.top = -1;

    push(&s, root);

    while(!isEmpty(&s)){
        struct TreeNode* node = pop(&s);
        printf("%d ", node->val);

        if(node->right)
            push(&s, node->right);

        if(node->left)
            push(&s, node->left);
    }
}
