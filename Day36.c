Problem1: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)
Output:
- Print queue elements from front to rear after operations, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
30 40 50 10 20
Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

Answer:
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int value) {
    if ((rear + 1) % n == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }

    queue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
}

int main() {
    int m, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}

Prblem2:Design your implementation of the circular double-ended queue (deque).
Implement the MyCircularDeque class:
MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
Example 1:
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]
Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
Constraints:
1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

Answer:
#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;
int k;

bool isFull() {
    if ((front == 0 && rear == k - 1) || (front == rear + 1))
        return true;
    return false;
}

bool isEmpty() {
    if (front == -1)
        return true;
    return false;
}

bool insertFront(int value) {
    if (isFull())
        return false;

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = k - 1;
    }
    else {
        front = front - 1;
    }

    deque[front] = value;
    return true;
}

bool insertLast(int value) {
    if (isFull())
        return false;

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == k - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }

    deque[rear] = value;
    return true;
}

bool deleteFront() {
    if (isEmpty())
        return false;

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == k - 1) {
        front = 0;
    }
    else {
        front = front + 1;
    }

    return true;
}

bool deleteLast() {
    if (isEmpty())
        return false;

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = k - 1;
    }
    else {
        rear = rear - 1;
    }

    return true;
}

int getFront() {
    if (isEmpty())
        return -1;
    return deque[front];
}

int getRear() {
    if (isEmpty())
        return -1;
    return deque[rear];
}

int main() {
    k = 3;  

    printf("%d\n", insertLast(1));  
    printf("%d\n", insertLast(2));  
    printf("%d\n", insertFront(3)); 
    printf("%d\n", insertFront(4)); 
    printf("%d\n", getRear());      
    printf("%d\n", isFull());       
    printf("%d\n", deleteLast());   
    printf("%d\n", insertFront(4)); 
    printf("%d\n", getFront());     

    return 0;
}
