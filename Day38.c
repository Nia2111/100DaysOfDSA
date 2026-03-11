Problem1: Deque (Double-Ended Queue)
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.
Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.
Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)
Input:
- Sequence of deque operations with values (if applicable)
Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations.

Answer:
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (front == -1)
        return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

void push_front(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

int get_front() {
    if (empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

int get_back() {
    if (empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    printf("Front element: %d\n", get_front());
    printf("Rear element: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    return 0;
}

Problem2:You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:
Input: nums = [1], k = 1
Output: [1]
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length.

Answer:
#include <stdio.h>

#define MAX 100000

void maxSlidingWindow(int nums[], int n, int k) {
    int dq[MAX];   
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        if (front <= rear && dq[front] <= i - k)
            front++;

        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        if (i >= k - 1)
            printf("%d ", nums[dq[front]]);
    }
}

int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int n = sizeof(nums)/sizeof(nums[0]);

    printf("Sliding Window Maximum: ");
    maxSlidingWindow(nums, n, k);

    return 0;
}
