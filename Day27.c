Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)
Output:
- Print value of intersection node or 'No Intersection'
Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50
Output:
30
Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

  
Answer:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d\n", p1->data);
            return;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection\n");
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, value;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    findIntersection(head1, head2);

    return 0;
}

Problem2:Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
Examples:
Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like
A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 
The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 
A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105

Answer:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void createCycle(struct Node* head, int pos) {
    if (pos < 0) return;

    struct Node* temp = head;
    struct Node* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (cycleNode != NULL)
        temp->next = cycleNode;
}

bool removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = NULL;
            return true;
        }
    }

    return false; 
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, pos;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    scanf("%d", &pos);

    createCycle(head, pos);

    if (removeCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
