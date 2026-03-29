Problem 1:Convert a binary tree into its mirror image by swapping left and right children at every node.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print inorder traversal of mirrored tree
Example:
Input:
7
1 2 3 4 5 6 7
Output:
7 3 6 1 5 2 4
Explanation:
Each node’s left and right children are swapped recursively.

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* queue = createQueue(n);

    enqueue(queue, root);

    int i = 1;
    while (i < n) {
        struct Node* current = dequeue(queue);

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(queue, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(queue, current->right);
        }
        i++;
    }

    return root;
}

void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    mirrorTree(root);

    inorder(root);

    return 0;
}

Problem2:Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:
Input: root = []
Output: []
Example 3:
Input: root = [0]
Output: [0]
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
Follow up: Can you flatten the tree in-place (with O(1) extra space)?

Answer:
#include <stdio.h>
#include <stdlib.h>

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

void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* temp = curr->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            temp->right = curr->right;

            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

void printList(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->right;
    }
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printList(root);
    return 0;
}
