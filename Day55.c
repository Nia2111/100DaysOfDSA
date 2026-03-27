Problem1:Print the nodes visible when the binary tree is viewed from the right side.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print right view nodes
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
1 3 6
Explanation:
At each level, the rightmost node is visible from the right view.

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
    struct Node* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        struct Node* current = dequeue(&q);

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

void rightView(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue(&q);

            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(&q, temp->left);
            if (temp->right)
                enqueue(&q, temp->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}

Problem2:Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Explanation:
Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
Explanation:
Example 3:
Input: root = [1,null,3]
Output: [1,3]
Example 4:
Input: root = []
Output: []
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void rightViewUtil(struct Node* root, int level, int *maxLevel) {
    if (root == NULL) return;

    if (level > *maxLevel) {
        printf("%d ", root->val);
        *maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightSideView(struct Node* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[100];
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightSideView(root);

    return 0;
}
