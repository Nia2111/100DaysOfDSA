Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)
Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
Example:
Input:
5
10 4
20 3
30 2
40 1
50 0
Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50
Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (temp->exp == 0)
                printf("%d", temp->coeff);
            else if (temp->exp == 1)
                printf("%dx", temp->coeff);
            else
                printf("%dx^%d", temp->coeff, temp->exp);

            struct Node* next = temp->next;
            while (next != NULL && next->coeff == 0)
                next = next->next;

            if (next != NULL)
                printf(" + ");
        }
        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}

Problem2:You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
Follow up: Could you solve it without reversing the input lists?

Answer:
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertFront(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next) printf(" ");
        head = head->next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int stack1[105], stack2[105];
    int top1 = -1, top2 = -1;

    // Push l1 digits into stack1
    while (l1) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    while (l2) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;

        if (top1 >= 0)
            sum += stack1[top1--];

        if (top2 >= 0)
            sum += stack2[top2--];

        carry = sum / 10;
        result = insertFront(result, sum % 10);
    }

    return result;
}

struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    if (!head) return newNode;

    struct ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    int n1, n2, x;
    struct ListNode *l1 = NULL, *l2 = NULL;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
